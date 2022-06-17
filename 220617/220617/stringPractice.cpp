#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;

	if (str.empty())
	{
		cout << "비어있드앙\n";
	}

	str = "졸려용";

	if (str.empty())
	{
		cout << "뭐 생겼네용\n";
	}

	cout << "이 문자열의 길이는 " << str.length() << "\n";
	cout << "이 문자열의 길이는 " << str.size() << "\n";
}