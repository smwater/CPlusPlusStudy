#include <iostream>

using namespace std;

int main()
{
	int scoreArray[10] = {};

	for (int i = 0; i < 10; i++)
	{
		cout << "�л� " << i + 1 << "�� ������ �Է��ϼ��� : ";
		cin >> scoreArray[i];
	}

	double average = 0.0;
	for (int i = 0; i < 10; i++)
	{
		average += scoreArray[i];
	}

	cout << "�� ���� ����� " << average / 10.0 << "�� �Դϴ�.\n";
}