#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char ch;
	while(1)
	{
		string str;

		do
		{
			ch = getchar();
			str += ch;
		} while (ch != '.');

		if (str.size() == 2 && ch == '.')
		{
			break;
		}

		stack<char> s;
		for (int i = 0; i < str.size(); i++)
		{

			if (str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else if (!(s.empty()) && ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[')))
			{
				s.pop();
			}
			else if (str[i] == ')' || str[i] == ']')
			{
				s.push(str[i]);
			}
		}

		if (s.empty())
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}