#pragma warning(disable:4996)
#include <stdio.h>

/// <summary>
/// 배열에 모든 원소를 더한다.
/// </summary>
/// <param name="a">정수 n개가 저장되어 있는 배열</param>
/// <param name="n">배열의 크기</param>
/// <returns>배열의 모든 원소를 더한 값</returns>
long long sum(int* a, int n) {
	long long result = 0LL;
	for (int i = 0; i < n; i++) {
		result += a[i];
	}

	return result;
}

// Swap() : 2개의 정수를 받아 서로 데이터를 교환
void Swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// islower() : 한 개의 문자를 받아 소문자인지 판별한다.
int islower(char ch) {
	if ('a' <= ch && ch <= 'z') {
		return 1;
	}
	else {
		return 0;
	}
}

// isupper()
int isupper(char ch) {
	if ('A' <= ch && ch <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}

// tolower()
char tolower(char ch) {
	if ('A' <= ch && ch <= 'Z'){
		return ch + 32;
	}
	else {
		return ch;
	}
}

// toupper()
char toupper(char ch) {
	if ('a' <= ch && ch <= 'z') {
		return ch - 32;
	}
	else {
		return ch;
	}
}

// strlne() : 문자열의 길이를 구하는 함수
// 배열을 받으려면 포인터를 사용해야 한다.
// 배열을 매개변수로 받는 함수는 배열의 크기를 같이 받는다.
// 문자열의 끝은 널 문자(Null Character)다. => 따라서 배열의 크기를 알지 않아도 끝을 알 수 있다.
// 매개변수 1개 => 문자열을 저장하기 위한 객체 => pointer to char
int strlen(const char* str) {
	// 어떻게 문자열의 길이를 구할 수 있을까?

	// 1. str은 문자열이다.
	// 2. 문자열의 끝은 널 문자다.
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}

	return i;
}

//strchr() : 문자열에서 특정 문자의 위치를 찾는 것
// 1. 문자가 있는 경우 => 그 문자의 위치
// 2. 문자가 없는 경우 => NULL
// char* pos = strchr("Hello", 'l');
// "Hello"
//    ↑
char* strchr(const char* str, const char ch) {
	while (*str != '\0') {
		if (*str == ch) {
			return (char*)str;
		}
	}

	return NULL;
}

int main()
{
	const char* str = "Hello";

	printf("%s 문자열에서 %c 문자는 %c에 있다.", str, 'l', strchr(str, 'l'));
	
	return 0;
}
