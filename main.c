#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 고급C프로그래밍 및 실습 프로젝트

struct tel // 한 사람의 정보(이름, 전화번호, 생일)을 저장하는 구조체 선언
{
	char *name;
	char *tel_no;
	char *birth;
};
typedef struct tel TEL;

void phonebook_registration(TEL **, int *, int *);
void phonebook_showall(TEL **, int *);
void phonebook_delete(TEL **, int *);
void phonebook_findbybirth(TEL **, int *);
void phonebook_regfromfile(TEL **, int *, int *);
void phonebook_regtofile(TEL **, int *);

int main()
{
	TEL **tel_list = NULL;
	int choice, count = 0, max_num;

	printf("Max_num:"); // 총 입력받을 수를 입력
	scanf("%d", &max_num);
	tel_list = (TEL **)malloc(max_num * sizeof(TEL *)); // 총 입력받을 수만큼 구조체 배열을 동적 메모리 할당

	while (1) // 사용자가 종료하기 전까지 무한 반복
	{
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: phonebook_registration(tel_list, &count, &max_num); break; // Registration
		case 2: phonebook_showall(tel_list, &count); break; // ShowAll
		case 3: phonebook_delete(tel_list, &count); break; // Delete
		case 4: phonebook_findbybirth(tel_list, &count); break; // FindByBirth
		case 5: phonebook_regfromfile(tel_list, &count, &max_num); break; // RegisteredFromFile
		case 6: phonebook_regtofile(tel_list, &count); return 0; // RegisterToFile & Exit
		}
	}
}

void phonebook_registration(TEL **pst, int *cnt, int *max) // 사용자로부터 이름, 전화번호, 생일을 입력받아 구조체 배열에 저장하는 함수
{
	TEL *tmp;
	int i, j;
	char temp[101];

	if (*cnt >= *max) // 최대 저장 가능 개수에 도달하면 경고를 출력
		printf("OVERFLOW\n");
	else
	{
		*(pst + *cnt) = (TEL *)malloc(sizeof(TEL)); // 등록시 한번에 하나씩 구조체 메모리 할당

		printf("Name:");
		scanf("%s", temp);
		(*(pst + *cnt))->name = (char *)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy((*(pst + *cnt))->name, temp);

		printf("Phone_number:");
		scanf("%s", temp);
		(*(pst + *cnt))->tel_no = (char *)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy((*(pst + *cnt))->tel_no, temp);

		printf("Birth:");
		scanf("%s", temp);
		(*(pst + *cnt))->birth = (char *)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy((*(pst + *cnt))->birth, temp);

		printf("<<%d>>\n", ++(*cnt));

		for (i = 0; i < *cnt - 1; i++) // 전체 자료를 이름순으로 정렬(삽입될 위치를 찾은 후, 나머지 자료 이동)
		{
			if (strcmp((*(pst + *cnt - 1))->name, (*(pst + i))->name) < 0)
			{
				tmp = *(pst + *cnt - 1);
				for (j = *cnt - 2; j >= i; j--)
				{
					*(pst + j + 1) = *(pst + j);
				}
				*(pst + i) = tmp;
			}
		}
	}
}

void phonebook_showall(TEL **pst, int *cnt) // 사용자로부터 입력받은 정보를 출력하는 함수
{
	int i;

	if (*cnt > 0)
	{
		for (i = 0; i < *cnt; i++)
		{
			printf("%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
		}
	}
}

void phonebook_delete(TEL **pst, int *cnt) // 사용자로부터 삭제하고 싶은 이름을 입력받아 구조체 배열에서 삭제하는 함수
{
	int i, j;
	char tmp_name[101];

	if (*cnt == 0) // 저장되어있는 값이 없으면 경고 출력
		printf("NO MEMBER\n");
	else
	{
		printf("Name:");
		scanf("%s", tmp_name);
		for (i = 0; i < *cnt; i++)
		{
			/*
			현재 주소에 있는 구조체 배열 맴버들의 메모리를 해제한 후
			다음 주소에 있는 구조체 배열 맴버들의 메모리 크기만큼
			현재 주소에 있는 구조체 배열 맴버들의 메모리에 할당한 후
			다음 주소에 있는 문자열을 현재 주소에 있는 문자열에 복사
			*/
			if (strcmp((*(pst + i))->name, tmp_name) == 0)
			{
				for (j = i; j < *cnt - 1; j++)
				{
					free((*(pst + j))->name);
					free((*(pst + j))->tel_no);
					free((*(pst + j))->birth);
					(*(pst + j))->name = (char *)malloc(strlen((*(pst + j + 1))->name) + 1);
					(*(pst + j))->tel_no = (char *)malloc(strlen((*(pst + j + 1))->tel_no) + 1);
					(*(pst + j))->birth = (char *)malloc(strlen((*(pst + j + 1))->birth) + 1);
					strcpy((*(pst + j))->name, (*(pst + j + 1))->name);
					strcpy((*(pst + j))->tel_no, (*(pst + j + 1))->tel_no);
					strcpy((*(pst + j))->birth, (*(pst + j + 1))->birth);
				}
				/*
				가장 마지막 주소에 있는 구조체 배열 맴버들의
				메모리를 해제하고 구조체 배열의 메모리도 해제
				그리고 동적 할당을 해제 했을 때 생긴
				댕글링 포인터도 제거
				*/
				free((*(pst + j))->name);
				free((*(pst + j))->tel_no);
				free((*(pst + j))->birth);
				free(*(pst + j));
				*(pst + j) = NULL;
				(*cnt)--;
				break;
			}
		}
	}
}

void phonebook_findbybirth(TEL **pst, int *cnt) // 사용자로부터 달을 입력받아 입력받은 달에 해당하는 사람을 출력하는 함수
{
	int i, birth_month, tmp_birth_month;

	printf("Birth:");
	scanf("%d", &birth_month);
	for (i = 0; i < *cnt; i++)
	{
		tmp_birth_month = atoi((*(pst + i))->birth);
		tmp_birth_month = (tmp_birth_month % 10000) / 100;
		if (birth_month == tmp_birth_month)
		{
			printf("%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
		}
	}
}
void phonebook_regfromfile(TEL **pst, int *cnt, int *max) // 같은 디렉토리에 있는 텍스트 파일에서 정보를 가져오는 함수
{
	FILE *fp = fopen("PHONE_BOOK.txt", "rt");
	TEL *tmp;
	int i, j;
	char temp_name[101], temp_tel_no[101], temp_birth[101];

	while (1)
	{
		if (*cnt >= *max) // 최대 저장 가능 개수에 도달하면 경고를 출력하고 파일에서 데이터 읽기를 멈춤
		{
			printf("OVERFLOW\n");
			break;
		}
		else
		{
			*(pst + *cnt) = (TEL *)malloc(sizeof(TEL)); // 등록시 한번에 하나씩 구조체 메모리 할당

			fscanf(fp, "%s %s %s", temp_name, temp_tel_no, temp_birth); // 파일에서 한 줄씩 읽음

			if (feof(fp)) // 파일의 끝에 도달하면 실행 중지
				break;

			(*(pst + *cnt))->name = (char *)malloc((strlen(temp_name) + 1) * sizeof(char));
			strcpy((*(pst + *cnt))->name, temp_name);

			(*(pst + *cnt))->tel_no = (char *)malloc((strlen(temp_tel_no) + 1) * sizeof(char));
			strcpy((*(pst + *cnt))->tel_no, temp_tel_no);

			(*(pst + *cnt))->birth = (char *)malloc((strlen(temp_birth) + 1) * sizeof(char));
			strcpy((*(pst + *cnt))->birth, temp_birth);

			(*cnt)++;

			for (i = 0; i < *cnt - 1; i++) // 전체 자료를 이름순으로 정렬(삽입될 위치를 찾은 후, 나머지 자료 이동)
			{
				if (strcmp((*(pst + *cnt - 1))->name, (*(pst + i))->name) < 0)
				{
					tmp = *(pst + *cnt - 1);
					for (j = *cnt - 2; j >= i; j--)
					{
						*(pst + j + 1) = *(pst + j);
					}
					*(pst + i) = tmp;
				}
			}
		}
	}
	fclose(fp);
}
void phonebook_regtofile(TEL **pst, int *cnt) // 같은 디렉토리에 있는 텍스트 파일에 정보를 저장하는 함수
{
	FILE *fp = fopen("PHONE_BOOK.txt", "wt");
	int i;

	for (i = 0; i < *cnt; i++)
		fprintf(fp, "%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
	fclose(fp);
}