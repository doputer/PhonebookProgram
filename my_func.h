#ifndef _MY_FUNC_H_ // 호출 함수의 원형들을 저장하는 헤더파일
#define _MY_FUNC_H_
void phonebook_registration(TEL **, int *, int *);
void phonebook_showall(TEL **, int *);
void phonebook_delete(TEL **, int *);
void phonebook_findbybirth(TEL **, int *);
void phonebook_sort(TEL **, int *);
void phonebook_change(TEL **, int *);
void phonebook_regfromfile(TEL **, int *, int *);
void phonebook_regtofile(TEL **, int *);
#endif

#ifndef _MY_BIRTH_FUNC_H_
#define _MY_BIRTH_FUNC_H_
void findbyyear(TEL **, int *);
void findbymonth(TEL **, int *);
void findbydate(TEL **, int *);
#endif

#ifndef _MY_SORT_FUNC_H_
#define _MY_SORT_FUNC_H_
void sortbyname(TEL **, int *);
void sortbybirth(TEL **, int *);
#endif