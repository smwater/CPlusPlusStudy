#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int map[25][25];
bool isVisited[25][25] = { false };

// ��ȯ ���� �ǹ̴� ���� �� ���� ����
int dfs(int r, int c)
{
	// ���� �湮���� �� => ���� ������ �ϳ� ���� ��
	isVisited[r][c] = true;

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
		if (isVisited[nr][nc] || map[nr][nc] == 0)
		{
			continue;
		}
		houseCount += dfs(nr, nc);
	}

	return houseCount;
}

int main()
{
	// 1. num�� �Է� �޴´�.
	cin >> num;

	// 2. ������ ����� �Է� �޴´�.
	for (int r = 0; r < num; r++)
	{
		for (int c = 0; c < num; c++)
		{
			scanf("%1d", &map[r][c]);
		}
	}

	// 3. ���� ���� ���� �� ���� ������ ���Ѵ�.
	int complexCount = 0;
	vector<int> houseCounts;
	for (int r = 0; r < num; r++)
	{
		for (int c = 0; c < num; c++)
		{
			// ���� ã�Ұ�, �湮���� �ʾҴٸ�?
			// dfs();
			if (1 == map[r][c] && false == isVisited[r][c])
			{
				int houseCount = dfs(r, c);
				houseCounts.push_back(houseCount);
				++complexCount;
			}
		}
	}
	sort(houseCounts.begin(), houseCounts.end());

	// 4. ����Ѵ�.
	cout << complexCount << "\n";
	for (int house : houseCounts)
		cout << house << "\n";
}