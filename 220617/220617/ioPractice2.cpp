#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#define widesize 12
#define num 4

int main()
{
	ofstream of("temp.txt");

	printf("printf() ¾´ ¹öÀü\n");
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

	static const char* name[num] = { "±èÀç¼º", "¿ëÁØÇå", "±èÀç¹Î", "±èµ¿Çö" };
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

	of << "\nstd::cout ¾´ ¹öÀü\n";
	of << setw(widesize * 2 + 4) << setfill('-') << "\n";
	of << setfill(' ') << "|";
	of << setw(widesize) << left << "Name" << "|";
	of << setw(widesize) << right << "Age" << "|\n";
	of << setw(widesize * 2 + 4) << setfill('-') << "\n";
	of << setfill(' ');

	for (int i = 0; i < num; i++)
	{
		of << "|";
		of << setw(widesize) << left << name[i] << "|";
		of << setw(widesize) << right << age[i] << "|\n";
	}

	of << setw(widesize * 2 + 4) << setfill('-') << "\n";

	of.close();
}