#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_struct.h"
#include "my_define.h"

void phonebook_delete(TEL **pst, int *cnt) // 사용자로부터 삭제하고 싶은 이름을 입력받아 구조체 배열에서 삭제하는 함수
{
	int i, j;
	char tmp_name[101];

	if (*cnt == 0) // 저장되어있는 값이 없으면 경고 출력
		printf("NO MEMBER\n");
	else
	{
		printf("Name:");
		scanf("%s", tmp_name);
		for (i = 0; i < *cnt; i++)
		{
			/*
			현재 주소에 있는 구조체 배열 맴버들의 메모리를 해제한 후
			다음 주소에 있는 구조체 배열 맴버들의 메모리 크기만큼
			현재 주소에 있는 구조체 배열 맴버들의 메모리에 할당한 후
			다음 주소에 있는 문자열을 현재 주소에 있는 문자열에 복사
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
				가장 마지막 주소에 있는 구조체 배열 맴버들의
				메모리를 해제하고 구조체 배열의 메모리도 해제
				그리고 동적 할당을 해제 했을 때 생긴
				댕글링 포인터도 제거
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