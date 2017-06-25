#pragma warning(disable:4996)
#include <stdio.h>
#include "my_struct.h"
#include "my_define.h"

void phonebook_regtofile(TEL **pst, int *cnt) // 같은 디렉토리에 있는 텍스트 파일에 정보를 저장하는 함수
{
	FILE *fp = fopen("PHONE_BOOK.txt", "wt");
	int i;

	for (i = 0; i < *cnt; i++)
		fprintf(fp, "%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
	fclose(fp);
}