#pragma warning(disable:4996)
#include <stdio.h>
#include "my_struct.h"
#include "my_define.h"

void phonebook_regtofile(TEL **pst, int *cnt) // ���� ���丮�� �ִ� �ؽ�Ʈ ���Ͽ� ������ �����ϴ� �Լ�
{
	FILE *fp = fopen("PHONE_BOOK.txt", "wt");
	int i;

	for (i = 0; i < *cnt; i++)
		fprintf(fp, "%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
	fclose(fp);
}