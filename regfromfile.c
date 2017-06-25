#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"

void phonebook_regfromfile(TEL **pst, int *cnt, int *max) // 같은 디렉토리에 있는 텍스트 파일에서 정보를 가져오는 함수
{
	FILE *fp = fopen("PHONE_BOOK.txt", "rt");
	char temp_name[101], temp_tel_no[101], temp_birth[101];

	while (1)
	{
		if (*cnt >= *max) // 최대 저장 가능 개수에 도달하면 경고를 출력하고 파일에서 데이터 읽기를 멈춤
		{
			printf("OVERFLOW\n");
			break;
		}
		else
		{
			*(pst + *cnt) = (TEL *)malloc(sizeof(TEL)); // 등록시 한번에 하나씩 구조체 메모리 할당

			fscanf(fp, "%s %s %s", temp_name, temp_tel_no, temp_birth); // 파일에서 한 줄씩 읽음

			if (feof(fp)) // 파일의 끝에 도달하면 실행 중지
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