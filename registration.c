#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

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