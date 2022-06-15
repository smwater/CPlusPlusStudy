#include <iostream>

using namespace std;

int main()
{
	int scoreArray[10] = {};

	for (int i = 0; i < 10; i++)
	{
		cout << "학생 " << i + 1 << "의 점수를 입력하세요 : ";
		cin >> scoreArray[i];
	}

	double average = 0.0;
	for (int i = 0; i < 10; i++)
	{
		average += scoreArray[i];
	}

	cout << "이 반의 평균은 " << average / 10.0 << "점 입니다.\n";
}