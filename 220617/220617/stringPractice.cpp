#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;

	if (str.empty())
	{
		cout << "����ֵ��\n";
	}

	str = "������";

	if (str.empty())
	{
		cout << "�� ����׿�\n";
	}

	cout << "�� ���ڿ��� ���̴� " << str.length() << "\n";
	cout << "�� ���ڿ��� ���̴� " << str.size() << "\n";
}