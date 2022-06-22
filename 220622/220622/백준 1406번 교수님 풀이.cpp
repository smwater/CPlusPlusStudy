#include <iostream>
#include <list>

using namespace std;

int main()
{
	// 0. 입출력 속도를 향상시킨다.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 문자열을 입력 받는다.
	string s;
	cin >> s;

	// 2. 명령어의 개수를 입력 받는다.
	int M;
	cin >> M;

	// 3. 명령어를 처리한다.
	list<char> lst(s.begin(), s.end());
	list<char>::iterator cursor = lst.end();
	while (M--)
	{
		// 3-1. 명령어를 입력 받는다.
		char op;
		cin >> op;

		// 3-2. 각 명령어에 맞게 실행한다.
		switch (op)
		{
		case 'L':
			if (cursor != lst.begin())
			--cursor;
			break;
		case 'D':
			if (cursor != lst.end())
			++cursor;
			break;
		case 'B':
			// 문자를 지운 후 커서 위치 업데이트 필요함.
			if (cursor != lst.begin())
			{
				--cursor;
				cursor = lst.erase(cursor);
			}
			break;
		case 'P':
			// 문자를 추가하기 전에 위치를 업데이트 해줘야 함.
			char param;
			cin >> param;

			cursor = lst.insert(cursor, param);
			++cursor;
			break;
		}
	}

	// 4. 출력
	for (list<char>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		cout << *iter;
	}
}