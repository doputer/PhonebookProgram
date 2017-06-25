#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

// ����ó ���α׷�

int main()
{
	TEL **tel_list = NULL;
	int choice, count = 0, max_num;

	printf("Max_num:"); // �� �Է¹��� ���� �Է�
	scanf("%d", &max_num);
	tel_list = (TEL **)malloc(max_num * sizeof(TEL *)); // �� �Է¹��� ����ŭ ����ü �迭�� ���� �޸� �Ҵ�

	while (1) // ����ڰ� �����ϱ� ������ ���� �ݺ�
	{
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Sort><6.Change><7.RegFromFile><8.RegToFile><9.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: phonebook_registration(tel_list, &count, &max_num); break; // Registration
		case 2: phonebook_showall(tel_list, &count); break; // ShowAll
		case 3: phonebook_delete(tel_list, &count); break; // Delete
		case 4: phonebook_findbybirth(tel_list, &count); break; // FindByBirth
		case 5: phonebook_sort(tel_list, &count); break; // Sort
		case 6: phonebook_change(tel_list, &count); break; // Change
		case 7: phonebook_regfromfile(tel_list, &count, &max_num); break; // RegisteredFromFile
		case 8: phonebook_regtofile(tel_list, &count); break; // RegisterToFile
		case 9: return 0; // Exit
		}
	}
}
