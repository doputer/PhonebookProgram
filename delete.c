#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"

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