#include <iostream>
#include <algorithm>

using namespace std;

int x[200000] = {};

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}

	sort(x, x + N);

	// 4. ���� �˻��� �� ������ ���� ������ ������ ������ �Ÿ� => [1, x[N - 1]]
	int s = 1, e = x[N - 1] + 1;
	int answer = 0;
	while (s < e)
	{
		// 4-1. �߾Ӱ��� ���� �ĺ��� ���Ѵ�.
		// s : 1, e : 10, m = 5
		int m = (s + e) / 2;

		// 4-2. ������ m �Ÿ���ŭ ����߷��� ��, �� ���� �����Ⱑ �ʿ����� ����Ѵ�.
		int count = 1;
		int dis = 0;
		for (int i = 0; i < N - 1; i++)
		{
			dis += x[i + 1] - x[i];
			if (dis >= m)
			{
				count++;
				dis = 0;
			}
		}

		if (count < C)
		{
			e = m;
		}
		else
		{
			// 4-3. �ִ� ���� �ֽ�ȭ
			if (answer < m)
			{
				answer = m;
			}
			// 4-4. �� ã�� �� �ִ��� ���� ����
			s = m + 1;
		}
	}

	// 5. �ִ� �Ÿ��� ����Ѵ�.
	cout << answer;
}