#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int chess[300][300] = {};
int T, I;
pair<int, int> startPos;
pair<int, int> movePos;

void moveKnight(int r, int c)
{
	queue<pair<int, int>> q;
	q.emplace(r, c);

	int move = 0;
	while (q.empty() == false)
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			if (r == movePos.first && c == movePos.second)
			{
				cout << move << "\n";
				return;
			}

			static const int dr[] = { -2, -2, 2, 2, -1, 1, -1, 1 };
			static const int dc[] = { -1, 1, -1, 1, -2, -2, 2, 2 };

			for (int j = 0; j < 8; j++)
			{
				int nr = r + dr[j];
				int nc = c + dc[j];

				if (nr < 0 || nr >= I || nc < 0 || nc >= I)
				{
					continue;
				}
				if (chess[nr][nc] == 0)
				{
					q.emplace(nr, nc);
				}
			}
		}

		move++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--)
	{
		cin >> I;

		cin >> startPos.first >> startPos.second;
		cin >> movePos.first >> movePos.second;

		moveKnight(startPos.first, startPos.second);
	}
}