#include <iostream>
#include <iomanip>

using namespace std;

#define widesize 12
#define num 4

int main()
{
	printf("printf() �� ����\n");
	for (int i = 0; i < widesize * 2 + 3; i++)
	{
		printf("-");
	}
	printf("\n");
	printf("|%*s|%*s|\n", -1 * widesize, "Name", widesize, "Age");
	for (int i = 0; i < widesize * 2 + 3; i++)
	{
		printf("-");
	}
	printf("\n");

	static const char* name[num] = { "���缺", "������", "�����", "�赿��" };
	static const int age[num] = { 31, 28, 25, 28 };
	for (int i = 0; i < num; i++)
	{
		printf("|%*s|%*d|\n", -1 * widesize, name[i], widesize, age[i]);
	}
	for (int i = 0; i < widesize * 2 + 3; i++)
	{
		printf("-");
	}
	printf("\n\n");

	/* ------------------------------------------------------------ */

	cout << "\nstd::cout �� ����\n";
	cout << setw(widesize * 2 + 4) << setfill('-') << "\n";
	cout << setfill(' ') << "|";
	cout << setw(widesize) << left << "Name" << "|";
	cout << setw(widesize) << right << "Age" << "|\n";
	cout << setw(widesize * 2 + 4) << setfill('-') << "\n";
	cout << setfill(' ');

	for (int i = 0; i < num; i++)
	{
		cout << "|";
		cout << setw(widesize) << left << name[i] << "|";
		cout << setw(widesize) << right << age[i] << "|\n";
	}

	cout << setw(widesize * 2 + 4) << setfill('-') << "\n";
}