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

	// 4. 이진 검색을 할 범위는 가장 인접한 공유기 사이의 거리 => [1, x[N - 1]]
	int s = 1, e = x[N - 1] + 1;
	int answer = 0;
	while (s < e)
	{
		// 4-1. 중앙값을 해의 후보로 정한다.
		// s : 1, e : 10, m = 5
		int m = (s + e) / 2;

		// 4-2. 실제로 m 거리만큼 떨어뜨렸을 때, 몇 개의 공유기가 필요한지 계산한다.
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
			// 4-3. 최대 길이 최신화
			if (answer < m)
			{
				answer = m;
			}
			// 4-4. 더 찾을 수 있는지 범위 조절
			s = m + 1;
		}
	}

	// 5. 최대 거리를 출력한다.
	cout << answer;
}