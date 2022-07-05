#include <iostream>

using namespace std;

char chess[50][50];
const char blackChess[8][9] = { "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
const char whiteChess[8][9] = { "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW" };
int N, M;

int compareChess(int r, int c)
{
	int bCount = 0, wCount = 0;
	for (int cr = r; cr < r + 8; cr++)
	{
		for (int cc = c; cc < c + 8; cc++)
		{
			if (chess[cr][cc] != blackChess[cr - r][cc - c])
			{
				bCount++;
			}
			if (chess[cr][cc] != whiteChess[cr - r][cc - c])
			{
				wCount++;
			}
		}
	}

	if (bCount <= wCount)
	{
		return bCount;
	}
	else
	{
		return wCount;
	}
}

int makeChess()
{
	int min = 64;
	for (int r = 0; r <= N - 8; r++)
	{
		for (int c = 0; c <= M - 8; c++)
		{
			int num = compareChess(r, c);
			if (min > num)
			{
				min = num;
			}
		}
	}

	return min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		cin >> chess[r];
	}

	cout << makeChess();
}