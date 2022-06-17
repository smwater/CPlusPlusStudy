#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "---------------------------\n";
	cout << "|";
	cout << setw(12) << left;
	cout << "Name" << "|";
	cout << setw(12) << right;
	cout << "Age" << "|\n";
	cout << "---------------------------\n";
	cout << "|";
	cout << setw(12) << left;
	cout << "���缺" << "|";
	cout << setw(12) << right;
	cout << "31" << "|\n";
	cout << "|";
	cout << setw(12) << left;
	cout << "������" << "|";
	cout << setw(12) << right;
	cout << "28" << "|\n";
	cout << "|";
	cout << setw(12) << left;
	cout << "�����" << "|";
	cout << setw(12) << right;
	cout << "25" << "|\n";
	cout << "|";
	cout << setw(12) << left;
	cout << "�赿��" << "|";
	cout << setw(12) << right;
	cout << "28" << "|\n";
	cout << "---------------------------\n\n\n";

	static const string name[4] = {"���缺", "������", "�����", "�赿��"};
	static const int age[4] = { 31, 28, 25, 28 };

	cout << "---------------------------\n";
	cout << "|";
	cout << setw(12) << left;
	cout << "Name" << "|";
	cout << setw(12) << right;
	cout << "Age" << "|\n";
	cout << "---------------------------\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "|";
		cout << setw(12) << left;
		cout << name[i] << "|";
		cout << setw(12) << right;
		cout << age[i] << "|\n";
	}
	cout << "---------------------------\n";
}