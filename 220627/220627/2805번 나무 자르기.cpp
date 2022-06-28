#include <iostream>

using namespace std;
using ll = long long;

ll arr[1000000] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll N, M;
	cin >> N >> M;

	ll max = 0;
	for (ll i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	ll s = 0, e = max + 1;
	ll result = 0;
	while (s < e)
	{
		ll m = (s + e) / 2;

		ll count = 0;
		for (ll i = 0; i < N; i++)
		{
			if (arr[i] - m >= 0)
			{
				count += arr[i] - m;
			}
		}

		if (count >= M)
		{
			if (result < m)
			{
				result = m;
			}
			s = m + 1;
		}
		else
		{
			e = m;
		}
	}

	cout << result << "\n";
}