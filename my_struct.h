#ifndef _MY_STRUCT_H_ // 구조체 타입을 선언하는 헤더파일
#define _MY_STRUCT_H_
struct tel // 한 사람의 정보(이름, 전화번호, 생일)을 저장하는 구조체 선언
{
	char *name;
	char *tel_no;
	char *birth;
};
#endif