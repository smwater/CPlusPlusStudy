#include <list>
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	list<char> listString(str.begin(), str.end());

	int count;
	cin >> count;

	list<char>::iterator cursor = listString.end();
	for (int i = 0; i < count; i++)
	{
		char command;
		cin >> command;

		switch (command)
		{
		case 'L':
			if (cursor != listString.begin())
			{
				--cursor;
			}
			break;
		case 'D':
			if (cursor != listString.end())
			{
				++cursor;
			}
			break;
		case 'B':
			if (cursor != listString.begin())
			{
				--cursor;
				cursor = listString.erase(cursor);
			}
			break;
		case 'P':
			char insertCh;
			cin >> insertCh;
			cursor = listString.insert(cursor, insertCh);
			++cursor;
			break;
		}
	}

	while(!(listString.empty()))
	{
		printf("%c", listString.front());
		listString.pop_front();
	}
}