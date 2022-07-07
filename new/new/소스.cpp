#include <iostream>
#include <algorithm>

using namespace std;

int as[10001];
int bs[10001];

int main()
{
	string A, B;
	cin >> A >> B;

	int _size = A.size();
	if (B.size() > _size)
	{
		_size = B.size();
	}

	for (int i = 0; i < _size; i++)
	{
		as[i] = A.back() - '0';
		A.pop_back();
	}

	for (int i = 0; i < _size; i++)
	{
		bs[i] = B.back() - '0';
		B.pop_back();
	}
	
	for (int i = 0; i < _size; i++)
	{
		cout << as[i] << " ";
	}

	cout << "\n";
	for (int i = 0; i < _size; i++)
	{
		cout << bs[i] << " ";
	}

}