// 실패~
// 당연함 동적 배열은 사이즈가 정해져 있는데
// stack은 사이즈가 정해져있지 않음~
#include <iostream>

using namespace std;

void stackPush(int* array, int num);
int stackSize(int* array);
void stackPop(int* array);
bool stackEmpty(int* array);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int* stackArray = new int;

	int N;
	cin >> N;
	while (N--)
	{
		string command;
		cin >> command;

		if (command == "push")
		{
			int num;
			cin >> num;

			stackPush(stackArray, num);
		}
		else if (command == "pop")
		{
			if (stackSize(stackArray) == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << stackArray[0] << "\n";
				stackPop(stackArray);
			}
		}
		else if (command == "size")
		{
			cout << stackSize(stackArray) << "\n";
		}
		else if (command == "empty")
		{
			if (stackEmpty(stackArray))
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
			if (stackEmpty(stackArray))
			{
				cout << "-1\n";
			}
			else
			{
				cout << stackArray[0] << "\n";
			}
		}
	}

	delete[] stackArray;
}

void stackPush(int* array, int num)
{
	int size = stackSize(array);
	if (size == 0)
	{
		*array = num;
	}
	else
	{
		while (size--)
		{
			int* temp = array;
			++array = temp;
		}
	}
}

int stackSize(int* array)
{
	int count = 0;
	while (*array != NULL)
	{
		++count;
		++array;
	}

	return count;
}

void stackPop(int* array)
{
	int size = stackSize(array);
	for (int i = 0; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}

	array[size - 1] = NULL;
}

bool stackEmpty(int* array)
{
	if (stackSize(array) == 0) 
	{
		return true;
	}
	else
	{
		return false;
	}
}