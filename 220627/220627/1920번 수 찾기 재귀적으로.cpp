#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

bool findNum(int s, int e, int num)
{
	if (s < e)
	{
		int m = (s + e) / 2;
		if (arr[m] == num)
		{
			return true;
		}
		else if (arr[m] < num)
		{
			findNum(m + 1, e, num);
		}
		else
		{
			findNum(s, m, num);
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		cout << findNum(0, N, num) << "\n";
	}
}