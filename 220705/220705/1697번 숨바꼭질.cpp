#include <iostream>
#include <queue>

using namespace std;

int Time[100000] = {};
int N, K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	queue<int> q;
	q.push(N);

	while (q.empty() == false)
	{
		int x = q.front();
		q.pop();

		if (x == K)
		{
			cout << Time[x] << "\n";
			return 0;
		}

		for (int i = 0; i < 3; i++)
		{
			int nx;

			switch (i)
			{
			case 0:
				nx = x - 1;
				break;
			case 1:
				nx = x + 1;
				break;
			case 2:
				nx = x * 2;
				break;
			}

			if (nx < 0 || nx > 100000)
			{
				continue;
			}
			if (Time[nx] != 0)
			{
				continue;
			}

			q.push(nx);
			Time[nx] = Time[x] + 1;
		}
	}
}