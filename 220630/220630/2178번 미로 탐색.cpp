#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int maze[100][100];
bool isVisited[100][100] = { false };

int searchMaze(int r, int c)
{
	queue<pair<int, int>> q;
	q.emplace(r, c);

	int move = 0;
	bool escaped = false;
	while (q.empty() == false && escaped == false)
	{
		int mr = q.front().first;
		int mc = q.front().second;
		isVisited[mr][mc] = true;
		q.pop();

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
			if (isVisited[nr][nc] || maze[nr][nc] == 0)
			{
				continue;
			}
			if (nr == N - 1 && nc == M - 1)
			{
				escaped = true;
				break;
			}

			q.emplace(nr, nc);
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
		for (int c = 0; c < M; c++)
		{
			scanf("%1d", &maze[r][c]);
		}
	}

	int move = 0;
	int newMove;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			if (maze[r][c] == 1 && isVisited[r][c] == false)
			{
				newMove = searchMaze(r, c);
			}
		}
	}

	printf("%d\n", move);
}