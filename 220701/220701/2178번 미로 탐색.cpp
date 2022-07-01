#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int N, M;
char maze[100][100];
bool isVisited[100][100] = { false };

int searchMaze(int r, int c)
{
	queue<pair<int, int>> q;
	q.emplace(r, c);

	int move = 1;
	
	while (q.empty() == false)
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			int mr = q.front().first;
			int mc = q.front().second;
			isVisited[mr][mc] = true;
			q.pop();

			if (mr == N - 1 && mc == M - 1)
			{
				return move;
			}

			static const int dr[] = { -1, 1, 0, 0 };
			static const int dc[] = { 0, 0, -1, 1 };

			for (int i = 0; i < 4; i++)
			{
				int nr = mr + dr[i];
				int nc = mc + dc[i];

				if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				{
					continue;
				}
				if (isVisited[nr][nc] || maze[nr][nc] != '1')
				{
					continue;
				}

				q.emplace(nr, nc);
			}

		}

		move++;
	}
	
	return move;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int r = 0; r < N; r++)
	{
		scanf("%s", &maze[r]);
	}

	int move = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (maze[r][c] == '1' && isVisited[r][c] == false)
			{
				move = searchMaze(r, c);
			}
		}
	}

	printf("%d\n", move);
}