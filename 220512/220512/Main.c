#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define UP (GetAsyncKeyState(VK_UP) & 0x8000)
#define DOWN (GetAsyncKeyState(VK_DOWN) & 0x8000)
#define LEFT (GetAsyncKeyState(VK_LEFT) & 0x8000)
#define RIGHT (GetAsyncKeyState(VK_RIGHT) & 0x8000)
#define SPACE (GetAsyncKeyState(VK_SPACE) & 0x8000)

int main(void) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	static clock_t s_prevTick;
	float s_deltatime;

	while (1) {
		static COORD playerPos = { 0, 0 };
		SetConsoleCursorPosition(h, playerPos);

		putchar('P');

		static float bulletTime = 0.f;
		static int shootBullet = 0;
		static COORD bulletPos = { 0, 0 };

		while (1) {
			if (SPACE) {
				if (shootBullet == 0) {
					shootBullet = 1;
					bulletPos.X = playerPos.X;
					bulletPos.Y = playerPos.Y;
					s_prevTick = clock();
					break;
				}
			}
			else if (UP && RIGHT) {
				if (playerPos.Y != 0) {
					playerPos.X++;
					playerPos.Y--;
					break;
				}
			}
			else if (DOWN && RIGHT) {
				playerPos.X++;
				playerPos.Y++;
				break;
			}
			else if (DOWN && LEFT) {
				if (playerPos.X != 0) {
					playerPos.X--;
					playerPos.Y++;
					break;
				}
			}
			else if (UP && LEFT) {
				if (playerPos.X != 0 && playerPos.Y != 0) {
					playerPos.X--;
					playerPos.Y--;
					break;
				}
			}
			else if (UP) {
				if (playerPos.Y != 0) {
					playerPos.Y--;
					break;
				}
			}
			else if (DOWN) {
				playerPos.Y++;
				break;
			}
			else if (LEFT) {
				if (playerPos.X != 0) {
					playerPos.X--;
					break;
				}
			}
			else if (RIGHT) {
				playerPos.X++;
				break;
			}
			break;
		}

		if (shootBullet == 1) {

			clock_t currentTick = clock();
			s_deltatime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC;
			s_prevTick = currentTick;
			bulletTime += s_deltatime;
			bulletPos.X++;
			SetConsoleCursorPosition(h, bulletPos);
			putchar('O');

			if (bulletTime >= 3.f) {
				shootBullet = 0;
				bulletTime = 0.f;
			}
		}

		Sleep(10);
		system("cls");
	}
}