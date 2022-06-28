#include <iostream>
#include <algorithm>

using namespace std;

int arr[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max <= arr[i])
		{
			max = arr[i];
		}
	}

	sort(arr, arr + N);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		int lowCount = N, highCount = 0;
		int s = 0, e = N;
		while (s < e)
		{
			int m = (s + e) / 2;

			if (arr[m] < num)
			{
				s = m + 1;
			}
			else if (arr[m] > num)
			{
				e = m;
			}
			else
			{
				if (lowCount > m)
				{
					lowCount = m;
				}
				e = m;
			}
		}
		s = 0, e = N;
		while (s < e)
		{
			int m = (s + e) / 2;

			if (arr[m] < num)
			{
				s = m + 1;
			}
			else if (arr[m] > num)
			{
				e = m;
			}
			else
			{
				if (highCount < m)
				{
					highCount = m;
				}
				s = m + 1;
			}
		}

		if (lowCount == N)
		{
			cout << 0 << " ";
		}
		else
		{
			cout << highCount - lowCount + 1 << " ";
		}
	}
}