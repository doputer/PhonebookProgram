#include <stdio.h>
#include "my_struct.h"
#include "my_define.h"

void phonebook_showall(TEL **pst, int *cnt) // 사용자로부터 입력받은 정보를 출력하는 함수
{
	int i;

	if (*cnt == 0) // 저장되어있는 값이 없으면 경고 출력
		printf("NO MEMBER\n");
	else
	{
		if (*cnt > 0)
		{
			for (i = 0; i < *cnt; i++)
			{
				printf("%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
			}
		}
	}
}