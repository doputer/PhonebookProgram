#include <stdio.h>
#include "my_struct.h"
#include "my_define.h"

void phonebook_showall(TEL **pst, int *cnt) // ����ڷκ��� �Է¹��� ������ ����ϴ� �Լ�
{
	int i;

	if (*cnt == 0) // ����Ǿ��ִ� ���� ������ ��� ���
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