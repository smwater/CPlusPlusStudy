#include <unordered_map>
#include <string>
#include <iostream>

enum Gender { MALE, FEMALE };

struct Student
{
	bool IsOnGlasses;
	Gender Gender;
	bool IsCodingGosu;
	int Age;
};

using namespace std;

ostream& operator<<(ostream& oss, const Student& student)
{
	oss << "---------------------------\n";
	if (student.IsOnGlasses)
	{
		oss << "이 학생은 안경을 썼습니다.\n";
	}
	else
	{
		oss << "이 학생은 안경을 쓰지 않았습니다.\n";
	}

	if (student.Gender == MALE)
	{
		oss << "이 학생은 남자입니다.\n";
	}
	else
	{
		oss << "이 학생은 여자입니다.\n";
	}

	if (student.IsCodingGosu)
	{
		oss << "이 학생은 코딩 고수입니다. 교수를 위협 중입니다.\n";
	}
	else
	{
		oss << "이 학생은 코딩 고수가 되기 위해 노력 중입니다.\n";
	}

	oss << "이 학생의 나이는 " << student.Age << "살 입니다.\n";
	oss << "---------------------------\n";

	return oss;
}

int main()
{
	hash<string> hash;
	// hash()에 어떤 값을 넣어도 8byte(unsigned long long) 크기로 변환됨
	size_t value = hash("zsdfasdfsfdd");

	unordered_map<string, Student> hashTable;

	hashTable["최서연"] = Student{ false, FEMALE, true, 22 };
	cout << hashTable["최서연"];
	// 우리 눈에는 "최서연" 이지만
	// 사실은 인덱스(af9643748328492384823974)가 생성 됐다
	// int a[5] => a[0] ~ a[4]
	// hashing으로 만들어지는 값들은
	// 0 ~ 4 다

	hashTable["박현수"] = Student{ true, FEMALE, false, 27 };
	cout << hashTable["박현수"];
}