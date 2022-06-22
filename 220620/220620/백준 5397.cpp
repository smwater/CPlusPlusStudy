#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	string testString;
	for (int count = 0; count < T; count++)
	{
		cin >> testString;

		list<char> testList;
		list<char>::iterator iter = testList.begin();
		for (int i = 0; i < testString.length(); i++)
		{
			switch (testString[i])
			{
			case '-':
				if (iter != testList.begin())
				{
					--iter;
					iter = testList.erase(iter);
				}
				break;
			case '<':
				if (iter != testList.begin())
				{
					--iter;
				}
				break;
			case '>':
				if (iter != testList.end())
				{
					++iter;
				}
				break;
			default:
				iter = testList.insert(iter, testString[i]);
				++iter;
				break;
			}
		}

		for (list<char>::iterator iter = testList.begin(); iter != testList.end(); ++iter)
		{
			cout << *iter;
		}

		cout << "\n";
	}
}