#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void myprintf2(int count, ...) {
	va_list args;
	va_start(args, count);

	printf("My Variadic Function :");
	for (int i = 0; i < count; i++) {
		int number = va_arg(args, int);
		printf(" %d,", number);
	}

	printf("\n");

	va_end(args);
}

/// <summary>
/// printf와 유사하게 동작하나 기능이 제한됨.
/// %d / %c / %s
/// </summary>
/// <param name="format">형식 문자열</param>
/// <param name="">가변 인자값</param>
void myprintf(const char* format, ...);

void putcharChangeInt(int );

int main(void) {
	myprintf2(3, 1, 2, 3);

	myprintf("Hello My Printf : %d, %c, %d, %c, %s", -358, 'a', 1234, '?', "skdjflsd");
}

void myprintf(const char* format, ...) {
	va_list args;
	va_start(args, format);

	while (putchar(*format) != '\0') {
		format++;

		if (*format == '%') {
			switch (*++format) {
			case 'd':
				putcharChangeInt(va_arg(args, int));
				break;
			case 'c':
				putchar(va_arg(args, char));
				break;
			case 's':
				// 여기도 만들어야함
				break;
			default:
				break;
			}
			++format;
		}
	}

	va_end(args);
}

void putcharChangeInt(int num) {
	if (num >= 0 && num < 10) {
		putchar(num + '0');
		return;
	}
	else if (num < 0 && num > -10) {
		putchar('-');
		num *= -1;
		putchar(num + '0');
		return;
	}

	int digit = 0;
	int originalNum = num;
	if (num >= 10) {
		while (num / 10 != 0) {
			digit++;
			num /= 10;
		}

		while (digit) {
			num = originalNum;
			for (int i = 0; i < digit; i++) {
				num /= 10;
			}
			putchar(num + '0');

			for (int i = 0; i < digit; i++) {
				num *= 10;
			}
			originalNum -= num;

			digit--;
		}

		putchar(originalNum % 10 + '0');

		return;
	}
	else if (num <= -10) {
		putchar('-');
		num *= -1;
		originalNum *= -1;

		while (num / 10 != 0) {
			digit++;
			num /= 10;
		}

		while (digit) {
			num = originalNum;
			for (int i = 0; i < digit; i++) {
				num /= 10;
			}
			putchar(num + '0');

			for (int i = 0; i < digit; i++) {
				num *= 10;
			}
			originalNum -= num;

			digit--;
		}

		putchar(originalNum % 10 + '0');

		return;
	}
}