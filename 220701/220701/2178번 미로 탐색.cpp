#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int N, M;
char maze[101][101] = {};

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
			q.pop();

			if (mr == N - 1 && mc == M - 1)
			{
				maze[mr][mc] == '2';
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
				if (maze[nr][nc] == '1')
				{
					q.emplace(nr, nc);
					maze[nr][nc] = '2';
				}
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
		scanf("%s", maze[r]);
	}

	int move = 0;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (maze[r][c] == '1')
			{
				maze[r][c] = '2';
				move = searchMaze(r, c);
				printf("%d\n", move);
				return 0;
			}
		}
	}
}