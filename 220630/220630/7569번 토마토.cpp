#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int box[100][100][100];
queue<pair<pair<int, int>, int>> q;

enum { EMPTY = -1, TOMATO, RIPENED };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> H;

	// 2. 토마토 상자의 정보를 입력 받는다.
	int tomatoCount = 0;
	for (int h = 0; h < H; h++)
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				cin >> box[h][r][c];

				if (box[h][r][c] == RIPENED)
				{
					q.push(make_pair(make_pair(h, r), c));
				}
				else if (box[h][r][c] == TOMATO)
				{
					tomatoCount++;
				}
			}
		}
	}

	if (tomatoCount == 0)
	{
		cout << 0;
		return 0;
	}

	// 3. 토마토를 숙성시켜야 함
	int day = 0;
	while (false == q.empty())
	{
		const int size = q.size();
		for (int d = 0; d < size; d++)
		{
			int h = q.front().first.first;
			int r = q.front().first.second;
			int c = q.front().second;
			q.pop();

			const int dh[] = { -1, 1, 0, 0, 0, 0 };
			const int dr[] = { 0, 0, -1, 1, 0, 0 };
			const int dc[] = { 0, 0, 0, 0, -1, 1 };

			for (int i = 0; i < 6; i++)
			{
				const int nh = h + dh[i];
				const int nr = r + dr[i];
				const int nc = c + dc[i];

				if (nh < 0 || nh >= H || nr < 0 || nr >= N || nc < 0 || nc >= M)
				{
					continue;
				}
				if (box[nh][nr][nc] == TOMATO)
				{
					q.push(make_pair(make_pair(nh, nr), nc));
					box[nh][nr][nc] = RIPENED;
					tomatoCount--;
				}
			}
		}
		day++;
	}

	// 4. 숙성일 수 출력
	if (tomatoCount > 0)
	{
		cout << -1;
	}
	else
	{
		cout << day - 1 << "\n";
	}
}