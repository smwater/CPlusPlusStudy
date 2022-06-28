#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

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

		bool isExist = false;
		int s = 0, e = N;
		while (s < e)
		{
			int m = (s + e) / 2;
			if (arr[m] == num)
			{
				isExist = true;
				break;
			}
			else if (arr[m] < num)
			{
				s = m + 1;
			}
			else
			{
				e = m;
			}
		}

		cout << isExist << "\n";
	}
}