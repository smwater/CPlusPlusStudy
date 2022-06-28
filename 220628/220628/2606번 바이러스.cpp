#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[101];

int countWarmVirus()
{
	bool isVisited[101] = { false };
	
	queue<int> q;
	q.push(1);
	isVisited[1] = true;

	int count = 0;
	while (false == q.empty())
	{
		int node = q.front();
		q.pop();

		for (int nextNode : vec[node])
		{
			if (false == isVisited[nextNode])
			{
				q.push(nextNode);
				isVisited[nextNode] = true;
				count++;
			}
		}
	}

	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int computer, pair;
	cin >> computer >> pair;

	while (pair--)
	{
		int o, t;
		cin >> o >> t;
		vec[o].push_back(t);
		vec[t].push_back(o);
	}

	int result = countWarmVirus();

	cout << result << "\n";
}