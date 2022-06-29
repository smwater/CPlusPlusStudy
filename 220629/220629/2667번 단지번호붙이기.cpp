#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int num;
vector<int> map[25];
bool isChecked[25][25] = { false };

int dfs(int r, int c)
{
	isChecked[r][c] = true;

	static const int dr[] = { -1, 1, 0, 0 };
	static const int dc[] = { 0, 0, -1, 1 };

	int houseCount = 1;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= num || nc < 0 || nc >= num)
		{
			continue;
		}
		if (isChecked[nr][nc] == true || map[nr][nc] == 0)
		{
			continue;
		}
		
		houseCount += dfs(nr, nc);
	}

	return houseCount;
}

void danjiNumMake()
{
	vector<int> houseCounts;
	int danji = 0;
	for (int r = 0; r < num; r++)
	{
		for (int c = 0; c < num; c++)
		{
			if (1 == map[r][c] && isChecked[r][c] == false)
			{
				int count = dfs(r, c);
				houseCounts.push_back(count);
				danji++;
			}
		}
	}

	cout << danji << "\n";
	sort(houseCounts.begin(), houseCounts.end());
	for (int c : houseCounts)
		cout << c << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> num;

	for (int r = 0; r < num; r++)
	{
		string s;
		cin >> s;
		for (int c = 0; c < num; c++)
		{
			int element = s[c] - '0';
			map[r].push_back(element);
		}
	}

	danjiNumMake();
}