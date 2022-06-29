#include <iostream>

using namespace std;

int M, N, K;
int map[50][50] = { 0 };
bool isVisited[50][50] = { false };

void DFS(int r, int c)
{
	isVisited[r][c] = true;
	map[r][c] = 0;

	static const int dr[] = { -1, 1, 0, 0 };
	static const int dc[] = { 0, 0, -1, 1 };
	
	for (int i = 0; i < 4; i++)
	{

		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= M || nc < 0 || nc >= N)
		{
			continue;
		}
		if (isVisited[nr][nc] || map[nr][nc] == 0)
		{
			continue;
		}

		DFS(nr, nc);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;

	while (T--)
	{

		cin >> M >> N >> K;

		while (K--)
		{
			int r, c;
			cin >> r >> c;

			map[r][c] = 1;
		}

		int warm = 0;
		for (int r = 0; r < M; r++)
		{
			for (int c = 0; c < N; c++)
			{
				if (1 == map[r][c] && false == isVisited[r][c])
				{
					DFS(r, c);
					warm++;
				}
			}
		}

		for (int r = 0; r < M; r++)
		{
			for (int c = 0; c < N; c++)
			{
				isVisited[r][c] = false;
			}
		}

		cout << warm << "\n";
	}
}