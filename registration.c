#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

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