#include <stdio.h>
#include "MyHeaderFile.h"
#include <time.h>
#include <stdlib.h>

#define SPEED_OF_LIGHT 299792458
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//int add(int* a, int* b) {
//	int c = 0;
//
//	return *a + *b;
//}
//
//void change(int* a) {
//	int c = 0;
//
//	*a = 30;
//}
//
//int isZero(int* a) {
//	int c = 0;
//
//	if (*a == 0) {
//		return 0;
//	}
//
//	return 1;
//}



int main(void) {
	/*int A = 10;
	int B = 20;

	int sum = add(&A, &B);
	printf("%d\n", sum);

	change(&A);
	printf("%d\n", A);

	isZero(&A);
	printf("%d", A);*/

	/*printf("빛의 속도는 %d m/s이다.\n", speed_of_light);

	if (min(10, 20)) {
		printf("10과 20 중에 작은 수는 10입니다.\n");
	}

#if 1
	puts("1. 이건 실행됨");
#endif

#if defined(test)
	puts("2. 이건 실행 안됨");
#else
	puts("2. 이건 실행됨");
#endif

#if !defined(test)
	puts("3. 이건 실행됨");
#else
	puts("3. 이건 실행 안됨");
#endif

#define test 
#ifdef test
	puts("4. 이건 실행됨");
#else
	puts("4. 이건 실행 안됨");
#endif*/

	/*srand(time(NULL));
	int num = rand();

	switch (num % 5) {
	case 0:
		printf("NULL\n");
		break;
	case 1:
		printf("리미트 브레이크\n");
		break;
	case 2:
		printf("네오\n");
		break;
	case 3:
		printf("우리 동네 코딩 대장\n");
		break;
	case 4:
		printf("코딩 참 쉽조");
		break;
	}*/
}