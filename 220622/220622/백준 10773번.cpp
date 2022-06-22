#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;
	cin >> K;

	list<int> cog;
	while (K--)
	{
		int num;
		cin >> num;

		if (num == 0 && cog.begin() != cog.end())
		{
			cog.pop_back();
		}
		else
		{
			cog.push_back(num);
		}
	}
	int sum = 0;
	for (list<int>::iterator iter = cog.begin(); iter != cog.end(); ++iter)
	{
		sum += *iter;
	}

	cout << sum;
}