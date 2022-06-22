#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		// 1. 문자열을 입력 받는다.
		string input;
		cin >> input;

		// 2. 컨테이너 2개를 만든다.
		// 하나는 커서 왼편에 존재하는 문자열로 정방향으로 저장
		// 다른 하나는 커서 오른편에 존재하는 문자열로 역방향으로 저장
		vector<char> left, rightReversed;

		// 컨테이너를 순회할 일이 너무 많다.
		// 근데, 순회할라니까 반복자 치기가 너무 귀찮다.
		for (char ch : input)
		{
			switch (ch)
			{
			case '>':
				if (false == left.empty())
				{
					rightReversed.push_back(left.back());
					left.pop_back();
				}
				break;
			case '<':
				if (false == rightReversed.empty())
				{
					left.push_back(rightReversed.back());
					rightReversed.pop_back();
				}
				break;
			case '-':
				if (false == left.empty())
				{
					left.pop_back();
				}
				break;
			default:
				left.push_back(ch);
			}
		}

		cout << string(left.begin(), left.end()) << string(rightReversed.rbegin(), rightReversed.rend()) << "\n";
	}
}