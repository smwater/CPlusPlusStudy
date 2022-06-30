#include <iostream>
#include <queue>

using namespace std;

int M, N;
int box[1000][1000];

enum { EMPTY = -1, TOMATO, RIPENED };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. M, N�� �Է� �޴´�.
	cin >> M >> N;

	// 2. �丶�� ������ ������ �Է� �޴´�.
	queue<pair<int, int>> q;
	int tomatoCount = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> box[r][c];
			
			if (box[r][c] == RIPENED)
			{
				q.emplace(r, c);
			}
			else if (box[r][c] == TOMATO)
			{
				tomatoCount++;
			}
		}
	}

	if (tomatoCount == 0)
	{
		cout << 0;
		return 0;
	}

	// 3. �丶�並 �������Ѿ� ��
	int day = 0;
	while (false == q.empty())
	{
		const int size = q.size();
		for (int d = 0; d < size; d++)
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			const int dr[] = { -1, 1, 0, 0 };
			const int dc[] = { 0, 0, -1, 1 };

			for (int i = 0; i < 4; i++)
			{
				const int nr = r + dr[i];
				const int nc = c + dc[i];

				if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				{
					continue;
				}
				if (box[nr][nc] == TOMATO)
				{
					q.emplace(nr, nc);
					box[nr][nc] = RIPENED;
					tomatoCount--;
				}
			}
		}
		day++;
	}

	// 4. ������ �� ���
	if (tomatoCount > 0)
	{
		cout << -1;
	}
	else 
	{
		cout << day - 1 << "\n";
	}
}