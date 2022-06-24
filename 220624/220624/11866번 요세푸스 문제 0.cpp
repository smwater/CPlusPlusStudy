#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int K;
	cin >> K;

	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		dq.push_back(i + 1);
	}
	
	cout << "<";
	deque<int>::iterator iter = dq.begin();
	while (dq.size() != 1)
	{
		for (int i = 0; i < K - 1; i++)
		{
			if (iter == dq.end())
			{
				iter = dq.begin();
			}

			++iter;
			
		}

		if (iter == dq.end())
		{
			iter = dq.begin();
		}

		cout << *iter << ", ";
		iter = dq.erase(iter);
	}

	cout << dq.front() << ">\n";
}