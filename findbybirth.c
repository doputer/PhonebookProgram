#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void phonebook_findbybirth(TEL **pst, int *cnt) // 사용자로부터 년, 월, 일 중 하나를 입력받아 입력받은 것에 해당하는 사람을 출력하는 함수
{
	int choice;

	if (*cnt == 0) // 저장되어있는 값이 없으면 경고 출력
		printf("NO MEMBER\n");
	else
	{
		printf("*****Menu*****\n");
		printf("<1.FindByYear><2.FindByMonth><3.FindByDate>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: findbyyear(pst, cnt); break; // FindByYear
		case 2: findbymonth(pst, cnt); break; // FindByMonth
		case 3: findbydate(pst, cnt); break; // FindByDate
		}
	}
}
void findbyyear(TEL **pst, int *cnt)
{
	int i, birth_year, tmp_birth_year;

	printf("Year:");
	scanf("%d", &birth_year);
	for (i = 0; i < *cnt; i++)
	{
		tmp_birth_year = atoi((*(pst + i))->birth);
		tmp_birth_year = tmp_birth_year / 10000;
		if (birth_year == tmp_birth_year)
		{
			printf("%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
		}
	}
}
void findbymonth(TEL **pst, int *cnt)
{
	int i, birth_month, tmp_birth_month;

	printf("Month:");
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
void findbydate(TEL **pst, int *cnt)
{
	int i, birth_date, tmp_birth_date;

	printf("Date:");
	scanf("%d", &birth_date);
	for (i = 0; i < *cnt; i++)
	{
		tmp_birth_date = atoi((*(pst + i))->birth);
		tmp_birth_date = tmp_birth_date % 100;
		if (birth_date == tmp_birth_date)
		{
			printf("%s %s %s\n", (*(pst + i))->name, (*(pst + i))->tel_no, (*(pst + i))->birth);
		}
	}
}