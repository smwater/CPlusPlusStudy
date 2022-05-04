#include <assert.h>
#include <stdio.h>
#include <float.h>

int main(void) {
	//std::cout << FLT_MIN;
	/*printf("float의 유효 숫자 : %d\n", FLT_DIG);
	printf("double의 유효 숫자 : %d\n", DBL_DIG);
	printf("long double의 유효 숫자 : %d\n", LDBL_DIG);

	assert(10 == 10);*/
	FILE* fp = NULL;

	if (0 != fopen_s(&fp, "Metaverse", "w")) {
		printf("오류 발생함.");

		return 1;
	}

	fputs("Hello File!", fp);
	fputc('J', fp);
	fprintf(fp, "\nThe name of the queen : %s\n", "퀸균지");

	fclose(fp);

	if (0 != fopen_s(&fp, "Metaverse", "r")) {
		printf("오류 발생함.");

		return 1;
	}

	char ch = fgetc(fp);
	char str[128] = "";
	fgets(str, sizeof(str), fp);
	char str2[128] = "";
	fscanf_s(fp, "The name of the queen : %s", str2, sizeof(str2));

	printf("읽어들인 문자 : %c\n", ch);
	printf("읽어들인 문자열 : %s\n", str);
	printf("퀸은 누구? : %s\n", str2);

	fclose(fp);

	// 바이너리 파일

	if (0 != fopen_s(&fp, "Metaverse2", "wb")) {
		printf("오류 발생함.");

		return 1;
	}

	struct Student {
		int Age;
		enum { A, B, O, AB } BloodType;
		char Name[24];
	};

	struct Student s = { 20, Student::A, "ChoiSeonMun"};

	if (1 != fwrite(&s, sizeof(s), 1, fp)) {
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	fclose(fp);

	if(0 != fopen_s(&fp, "Metaverse2", "rb")) {
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	struct Student s2 = { 0 };
	if (1 != fread(&s2, sizeof(s2), 1, fp)) {
		printf("오류 발생함.");

		fclose(fp);

		return 1;
	}

	printf("나이 : %d, 혈액형 : %d, 이름 : %s\n", s2.Age, s2.BloodType, s2.Name);

	fclose(fp);

	return 0;
}