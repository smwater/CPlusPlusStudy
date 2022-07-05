#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>

#define Q_SIZE (1 << 15)

int move[300][300];
int T, I;
struct { int R = 0; int C = 0; } Q[Q_SIZE], start, end;
int p, b;

void push(int r, int c)
{
	Q[p] = { r, c };
	p = (p + 1) % Q_SIZE;
}

void pop(int& r, int& c)
{
	r = Q[b].R;
	c = Q[b].C;
	b = (b + 1) % Q_SIZE;
}

int bfs()
{
	static int dr[] = { -2, -2, 2, 2, -1, 1, -1, 1 };
	static int dc[] = { -1, 1, -1, 1, -2, -2, 2, 2 };

	p = b = 0;
	push(start.R, start.C);

	while (p != b)
	{
		int r, c;
		pop(r, c);

		if (r == end.R && c == end.C)
		{
			return move[r][c];
		}

		for (int i = 0; i < 8; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= I || nc < 0 || nc >= I)
			{
				continue;
			}
			if (nr == start.R && nc == start.C)
			{
				continue;
			}
			if (move[nr][nc] != 0)
			{
				continue;
			}
			
			move[nr][nc] = move[r][c] + 1;
			push(nr, nc);
		}
	}
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &I);
		scanf("%d %d", &start.R, &start.C);
		scanf("%d %d", &end.R, &end.C);

		printf("%d\n", bfs());

		memset(move, 0, sizeof(move));
	}
}