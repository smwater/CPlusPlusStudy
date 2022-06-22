#include <stack>
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	stack<int> intStack;
	while (N--)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;

			intStack.push(num);
		}
		else if (command == "pop")
		{
			if (intStack.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << intStack.top() << "\n";
				intStack.pop();
			}
		}
		else if (command == "size")
		{
			cout << intStack.size() << "\n";
		}
		else if (command == "empty")
		{
			if (intStack.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else if (command == "top")
		{
			if (intStack.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << intStack.top() << "\n";
			}
		}
	}
}