#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		string str;
		cin >> str;

		stack<char> s;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				s.push('(');
			}
			else if (str[i] == ')' && !(s.empty()) && s.top() == '(')
			{
				s.pop();
			}
			else
			{
				s.push(str[i]);
			}
		}

		if (s.empty())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}