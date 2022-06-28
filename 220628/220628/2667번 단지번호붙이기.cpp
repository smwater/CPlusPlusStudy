#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[25];
int num;

void danjiNumMake()
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (1 == vec[i][j])
			{

			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < num; j++)
		{
			int element = s[j] - '0';
			vec[i].push_back(element);
		}
	}
}