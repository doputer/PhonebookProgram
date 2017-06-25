#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"

void phonebook_regfromfile(TEL **pst, int *cnt, int *max) // ���� ���丮�� �ִ� �ؽ�Ʈ ���Ͽ��� ������ �������� �Լ�
{
	FILE *fp = fopen("PHONE_BOOK.txt", "rt");
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
		}
	}
	fclose(fp);
}