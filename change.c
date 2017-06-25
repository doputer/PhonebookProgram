#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void phonebook_change(TEL **pst, int *cnt)
{
	int i;
	char temp[101];

	if (*cnt == 0) // 저장되어있는 값이 없으면 경고 출력
		printf("NO MEMBER\n");
	else
	{
		printf("Name:");
		scanf("%s", temp);

		for (i = 0; i < *cnt; i++)
		{
			if (strcmp(temp, (*(pst + i))->name) == 0)
			{
				free((*(pst + i))->tel_no);
				printf("Phone_number:");
				scanf("%s", temp);
				(*(pst + i))->tel_no = (char *)malloc(strlen(temp) + 1);
				strcpy((*(pst + i))->tel_no, temp);

				free((*(pst + i))->birth);
				printf("Birth:");
				scanf("%s", temp);
				(*(pst + i))->birth = (char *)malloc(strlen(temp) + 1);
				strcpy((*(pst + i))->birth, temp);
			}
		}
	}
}