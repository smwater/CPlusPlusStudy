#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int insert[8];
	string answer = "";
	for (int i = 0; i < 8; i++)
	{
		cin >> insert[i];
	}

	for (int i = 0; i < 8; i++)
	{
		if (insert[i] == i + 1 && (answer == "" || answer == "ascending"))
		{
			answer = "ascending";
		}
		else if (insert[i] == 8 - i && (answer == "" || answer == "descending"))
		{
			answer = "descending";
		}
		else
		{
			answer = "mixed";
			break;
		}
	}

	cout << answer;
}