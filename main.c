#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���C���α׷��� �� �ǽ� ������Ʈ

struct tel // �� ����� ����(�̸�, ��ȭ��ȣ, ����)�� �����ϴ� ����ü ����
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

	printf("Max_num:"); // �� �Է¹��� ���� �Է�
	scanf("%d", &max_num);
	tel_list = (TEL **)malloc(max_num * sizeof(TEL *)); // �� �Է¹��� ����ŭ ����ü �迭�� ���� �޸� �Ҵ�

	while (1) // ����ڰ� �����ϱ� ������ ���� �ݺ�
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

void phonebook_registration(TEL **pst, int *cnt, int *max) // ����ڷκ��� �̸�, ��ȭ��ȣ, ������ �Է¹޾� ����ü �迭�� �����ϴ� �Լ�
{
	TEL *tmp;
	int i, j;
	char temp[101];

	if (*cnt >= *max) // �ִ� ���� ���� ������ �����ϸ� ��� ���
		printf("OVERFLOW\n");
	else
	{
		*(pst + *cnt) = (TEL *)malloc(sizeof(TEL)); // ��Ͻ� �ѹ��� �ϳ��� ����ü �޸� �Ҵ�

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

		for (i = 0; i < *cnt - 1; i++) // ��ü �ڷḦ �̸������� ����(���Ե� ��ġ�� ã�� ��, ������ �ڷ� �̵�)
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

void phonebook_showall(TEL **pst, int *cnt) // ����ڷκ��� �Է¹��� ������ ����ϴ� �Լ�
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

void phonebook_delete(TEL **pst, int *cnt) // ����ڷκ��� �����ϰ� ���� �̸��� �Է¹޾� ����ü �迭���� �����ϴ� �Լ�
{
	int i, j;
	char tmp_name[101];

	if (*cnt == 0) // ����Ǿ��ִ� ���� ������ ��� ���
		printf("NO MEMBER\n");
	else
	{
		printf("Name:");
		scanf("%s", tmp_name);
		for (i = 0; i < *cnt; i++)
		{
			/*
			���� �ּҿ� �ִ� ����ü �迭 �ɹ����� �޸𸮸� ������ ��
			���� �ּҿ� �ִ� ����ü �迭 �ɹ����� �޸� ũ�⸸ŭ
			���� �ּҿ� �ִ� ����ü �迭 �ɹ����� �޸𸮿� �Ҵ��� ��
			���� �ּҿ� �ִ� ���ڿ��� ���� �ּҿ� �ִ� ���ڿ��� ����
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
				���� ������ �ּҿ� �ִ� ����ü �迭 �ɹ�����
				�޸𸮸� �����ϰ� ����ü �迭�� �޸𸮵� ����
				�׸��� ���� �Ҵ��� ���� ���� �� ����
				��۸� �����͵� ����
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

void phonebook_findbybirth(TEL **pst, int *cnt) // ����ڷκ��� ���� �Է¹޾� �Է¹��� �޿� �ش��ϴ� ����� ����ϴ� �Լ�
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
void phonebook_regfromfile(TEL **pst, int *cnt, int *max) // ���� ���丮�� �ִ� �ؽ�Ʈ ���Ͽ��� ������ �������� �Լ�
{
	FILE *fp = fopen("PHONE_BOOK.txt", "rt");
	TEL *tmp;
	int i, j;
	char temp_name[101], temp_tel_no[101], temp_birth[101];

	while (1)
	{
		if (*cnt >= *max) // �ִ� ���� ���� ������ �����ϸ� ��� ����ϰ� ���Ͽ��� ������ �б⸦ ����
		{
			printf("OVERFLOW\n");
			break;
		}
		else
		{
			*(pst + *cnt) = (TEL *)malloc(sizeof(TEL)); // ��Ͻ� �ѹ��� �ϳ��� ����ü �޸� �Ҵ�

			fscanf(fp, "%s %s %s", temp_name, temp_tel_no, temp_birth); // ���Ͽ��� �� �پ� ����

			if (feof(fp)) // ������ ���� �����ϸ� ���� ����
				break;

			(*(pst + *cnt))->name = (char *)malloc((strlen(temp_name) + 1) * sizeof(char));
			strcpy((*(pst + *cnt))->name, temp_name);

			(*(pst + *cnt))->tel_no = (char *)malloc((strlen(temp_tel_no) + 1) * sizeof(char));
			strcpy((*(pst + *cnt))->tel_no, temp_tel_no);

			(*(pst + *cnt))->birth = (char *)malloc((strlen(temp_birth) + 1) * sizeof(char));
			strcpy((*(pst + *cnt))->birth, temp_birth);

			(*cnt)++;

			for (i = 0; i < *cnt - 1; i++) // ��ü �ڷḦ �̸������� ����(���Ե� ��ġ�� ã�� ��, ������ �ڷ� �̵�)
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
void phonebook_regtofile(TEL **pst, int *cnt) // ���� ���丮�� �ִ� �ؽ�Ʈ ���Ͽ� ������ �����ϴ� �Լ�
{
	FILE *fp = fopen("PHONE_BOOK.txt", "wt");
	int i;

	for (i = 0; i < *cnt; i++)
		fprintf(fp, "%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
	fclose(fp);
}