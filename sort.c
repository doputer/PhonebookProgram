#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void phonebook_sort(TEL **pst, int *cnt)
{
	int choice;

	if (*cnt == 0) // ����Ǿ��ִ� ���� ������ ��� ���
		printf("NO MEMBER\n");
	else
	{
		printf("*****Menu*****\n");
		printf("<1.SortByName><2.SortByBirth>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: sortbyname(pst, cnt); break; // SortByName
		case 2: sortbybirth(pst, cnt); break; // SortByBirth
		}
	}
}
void sortbyname(TEL **pst, int *cnt) // ��ü �ڷḦ �̸������� ��������
{
	TEL *tmp;
	int i, j;

	for (i = 0; i < *cnt - 1; i++)
	{
		for (j = 0; j < *cnt - 1 - i; j++)
		{
			if (strcmp((*(pst + j))->name, (*(pst + j + 1))->name) > 0)
			{
				tmp = *(pst + j);
				*(pst + j) = *(pst + j + 1);
				*(pst + j + 1) = tmp;
			}
		}
	}
}
void sortbybirth(TEL **pst, int *cnt) // ��ü �ڷḦ ���ϼ����� ��������
{
	TEL *tmp;
	int i, j;

	for (i = 0; i < *cnt - 1; i++) // ��ü �ڷḦ �ϼ����� ����
	{
		for (j = 0; j < *cnt - 1 - i; j++)
		{
			if (atoi((*(pst + j))->birth) % 100 < atoi((*(pst + j + 1))->birth) % 100)
			{
				tmp = *(pst + j);
				*(pst + j) = *(pst + j + 1);
				*(pst + j + 1) = tmp;
			}
		}
	}
	for (i = 0; i < *cnt - 1; i++) // ��ü �ڷḦ �޼����� ����
	{
		for (j = 0; j < *cnt - 1 - i; j++)
		{
			if ((atoi((*(pst + j))->birth) % 10000) / 100 < (atoi((*(pst + j + 1))->birth) % 10000) / 100)
			{
				tmp = *(pst + j);
				*(pst + j) = *(pst + j + 1);
				*(pst + j + 1) = tmp;
			}
		}
	}
	for (i = 0; i < *cnt - 1; i++) // ��ü �ڷḦ ������� ����
	{
		for (j = 0; j < *cnt - 1 - i; j++)
		{
			if (atoi((*(pst + j))->birth) / 10000 < atoi((*(pst + j + 1))->birth) / 10000)
			{
				tmp = *(pst + j);
				*(pst + j) = *(pst + j + 1);
				*(pst + j + 1) = tmp;
			}
		}
	}
}