// ���α׷� ����
// 1. �÷��̾�� ȭ��ǥ�� �����δ�.
// 2. �÷��̾�� P�� ǥ���Ѵ�.
// 3. �÷��̾ �̵��� �� �ִ� ������ �������̴�.
// 4. �����̽� Ű�� ������ �Ѿ��� �߻�ȴ�.�Ѿ��� �÷��̾� �ٷ� �տ� �����ȴ�.
// 5. �Ѿ��� O�� ǥ���Ѵ�.
// 6. �Ѿ��� 3�ʰ� ������ �� �����̴� 3�ʰ� ������ �������.
// 7. ����� ���� �Լ��� �����ȴ�.
// 8. ��ũ�δ� ��� �����ϴ�.
// 9. ��ŸŸ�� ������ ����Ǿ� �־�� �Ѵ�.
// 10. ��� �ĺ��ڴ� �������� ���ƾ� �Ѵ�.
// 11. �����ִ� ��ü�� ��� ����ü�� ǥ���Ѵ�.
// 12. ��� ��ü�� ����ϴ� ���� ������ ��ġ�ؾ� �Ѵ�.								
// 13. ���� ������ ������ ���� �Է� - ó�� - ��ºΰ� Ȯ���ϰ� ������ �־�� �Ѵ�.

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

// if������ ����ϱ� ���� ��ũ�� �Լ� ���
#define PRESS(KEY) (GetAsyncKeyState(KEY) & 0x8000)

// �÷��̾ ������ ȭ���� ũ�� ����
// MAX���� ���� ����
#define X_MIN 0
#define Y_MIN 0
#define X_MAX 120
#define Y_MAX 25

// ���ڿ� ����
#define W_STRING_NUMBER 3
// ���ڿ� ����
#define W_STRING_LENGTH 50

struct GameTitle
{
	COORD Pos[W_STRING_NUMBER];						// Ÿ��Ʋ�� ���ں� ��ǥ
	wchar_t Data[W_STRING_NUMBER][W_STRING_LENGTH];	// Ÿ��Ʋ�� ����
} GameTitle;

struct Player
{
	COORD Pos;			// �÷��̾��� ��ǥ
} Player;

struct Bullet
{
	COORD Pos;			// �Ѿ��� ��ǥ
	float AliveTime;	// �Ѿ��� ������ �ð�
	bool IsShoot;		// �Ѿ��� ���� ��� �ִ��� ���θ� Ȯ���ϴ� ��
} Bullet;

int main(void)
{
	struct GameTitle gameTitle;
	gameTitle.Data;
	wchar_t inputString[W_STRING_NUMBER][W_STRING_LENGTH] = {L"�����̽�Ű��", L"������", L"�������� �Ѿ�ϴ�."};

	for (int index = 0; index < W_STRING_NUMBER; index++) {
		wcscpy_s(gameTitle.Data[index], wcslen(inputString[index]) * 2, inputString[index]);
	}

	// ���� ȭ���� �ڵ��� ������
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// �����ڵ� ���ڸ� ����ϱ� ���� ������ ������ ����
	setlocale(LC_ALL, "KOREAN");

	gameTitle.Pos[0].X = 10;
	gameTitle.Pos[0].Y = 0;
	gameTitle.Pos[1].X = gameTitle.Pos[0].X + wcslen(gameTitle.Data[0]) * 2 + 1;
	gameTitle.Pos[1].Y = 10;
	gameTitle.Pos[2].X = gameTitle.Pos[1].X + wcslen(gameTitle.Data[1]) * 2 + 1;
	gameTitle.Pos[2].Y = 20;

	while (!PRESS(VK_SPACE)) // �����̽� �ٷ� ȭ�� ��ȯ
	{
		for (int index = 0; index < W_STRING_NUMBER; index++)
		{
			SetConsoleCursorPosition(h, gameTitle.Pos[index]);
			wprintf_s(gameTitle.Data[index]);
			
			if (gameTitle.Pos[index].Y != 10)
			{
				if (index == 0) 
				{
					gameTitle.Pos[index].Y++;
				}
				if (index == 2)
				{
					gameTitle.Pos[index].Y--;
				}
			}
			else
			{
				if (index == 0)
				{
					gameTitle.Pos[index].Y = 0;
				}
				if (index == 2)
				{
					gameTitle.Pos[index].Y = 20;
				}
			}
		}
		Sleep(10);
		system("cls");
	}

	// ȭ�� ��ȯ�� ���� �Է��� �����̽��ٰ�
	// ���� ȭ�鿡 ������ ��ġ�� �ʱ� ����
	// Sleep���� ��� ������
	Sleep(100);
	system("cls");

	// ����ü�� ��ü ����
	struct Player player;
	struct Bullet bullet;

	// ����� ���� �ʱ�ȭ
	player.Pos.X = 0;
	player.Pos.Y = 0;

	bullet.Pos.X = player.Pos.X;
	bullet.Pos.Y = player.Pos.Y;

	bullet.IsShoot = false;

	clock_t prevTick = 0.f;

	while (1)
	{
		// �Էº�
		// �� Ű�� �Է��� �޾� �÷��̾��� �̵� ó��
		if (PRESS(VK_SPACE) && bullet.IsShoot == false)
		{
			bullet.IsShoot = true;
			bullet.Pos.X = player.Pos.X;
			bullet.Pos.Y = player.Pos.Y;
			prevTick = clock();
		}
		if (PRESS(VK_UP) && player.Pos.Y != Y_MIN)
		{
			player.Pos.Y--;
		}
		if (PRESS(VK_DOWN) && player.Pos.Y != Y_MAX)
		{
			player.Pos.Y++;
		}
		if (PRESS(VK_LEFT) && player.Pos.X != X_MIN)
		{
			player.Pos.X--;
		}
		if (PRESS(VK_RIGHT) && player.Pos.X != X_MAX)
		{
			player.Pos.X++;
		}
		// �Էº�

		// ó����
		// ����� ���� ���� �� �ʱ�ȭ
		float deltatime;
		bullet.AliveTime = 0.f;
		if (bullet.IsShoot == true)
		{
			// ��Ÿ Ÿ�� ����
			clock_t currentTick = clock();
			deltatime = (float)(currentTick - prevTick) / CLOCKS_PER_SEC;
			bullet.AliveTime += deltatime;

			// �Ѿ��� ��ġ ó��
			bullet.Pos.X++;

			// ���� ƽ�� ���� ƽ���� ����
			prevTick = currentTick;

			// �⺻������ 3�ʰ� ������ �Ѿ��� ����������
			// ���� ȭ���� �Ѿ�� �����ǰ� ����
			if (bullet.AliveTime >= 3.f || bullet.Pos.X == X_MAX)
			{
				bullet.IsShoot = false;
				bullet.AliveTime = 0.f;
			}
		}
		// ó����

		// ��º�
		// �÷��̾� ��ġ�� ���� 'P' ���
		SetConsoleCursorPosition(h, player.Pos);
		putchar('P');

		// �Ѿ��� ��� �ִٸ� '0'�� ���
		if (bullet.IsShoot)
		{
			SetConsoleCursorPosition(h, bullet.Pos);
			putchar('O');
		}

		Sleep(10);
		system("cls");
		// ��º�
	}
}