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
		// 1. ���ڿ��� �Է� �޴´�.
		string input;
		cin >> input;

		// 2. �����̳� 2���� �����.
		// �ϳ��� Ŀ�� ���� �����ϴ� ���ڿ��� ���������� ����
		// �ٸ� �ϳ��� Ŀ�� ������ �����ϴ� ���ڿ��� ���������� ����
		vector<char> left, rightReversed;

		// �����̳ʸ� ��ȸ�� ���� �ʹ� ����.
		// �ٵ�, ��ȸ�Ҷ�ϱ� �ݺ��� ġ�Ⱑ �ʹ� ������.
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