#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> map[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int r = 0; r < N; r++)
	{
		string s;
		cin >> s;
		for (int c = 0; c < M; c++)
		{
			int block = s[c] - '0';
			map[r].push_back(block);
		}
	}


}