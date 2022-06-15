#include <iostream>

using namespace std;

int main()
{
	char Map[10][10] = {};

	int playerX = 0;
	int playerY = 0;

	while (Map[8][8] != 'P')
	{
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				Map[r][c] = '#';
			}
		}
		Map[8][8] = 'E';
		Map[playerY][playerX] = 'P';

		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				cout << Map[r][c];
			}
			cout << endl;
		}
		
		cout << "����Ű�� �Է��ϼ��� : ";
		char key;
		cin >> key;

		switch (key)
		{
		case 'w':
			if (playerY != 0)
			{
				playerY--;
			}
			break;
		case 'a':
			if (playerX != 0)
			{
				playerX--;
			}
			break;
		case 's':
			if (playerY != 9)
			{
				playerY++;
			}
			break;
		case 'd':
			if (playerX != 9)
			{
				playerX++;
			}
			break;
		}

		system("cls");
	}

	cout << "Ż�� ����\n";
}