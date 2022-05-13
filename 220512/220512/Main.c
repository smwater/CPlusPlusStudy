// 프로그램 조건
// 1. 플레이어는 화살표로 움직인다.
// 2. 플레이어는 P로 표현한다.
// 3. 플레이어가 이동할 수 있는 범위는 제한적이다.
// 4. 스페이스 키를 누르면 총알이 발사된다.총알은 플레이어 바로 앞에 생성된다.
// 5. 총알은 O로 표현한다.
// 6. 총알은 3초간 앞으로 쭉 움직이다 3초가 지나면 사라진다.
// 7. 사용자 정의 함수는 금지된다.
// 8. 매크로는 사용 가능하다.
// 9. 델타타임 개념이 적용되어 있어야 한다.
// 10. 모든 식별자는 가독성이 좋아야 한다.
// 11. 관련있는 객체는 묶어서 구조체로 표현한다.
// 12. 모든 객체는 사용하는 곳과 가까이 위치해야 한다.								
// 13. 게임 루프의 순서에 맞춰 입력 - 처리 - 출력부가 확실하게 나눠져 있어야 한다.

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

// if문에서 사용하기 쉽게 매크로 함수 사용
#define PRESS(KEY) (GetAsyncKeyState(KEY) & 0x8000)

// 플레이어가 움직일 화면의 크기 제한
// MAX값은 조정 가능
#define X_MIN 0
#define Y_MIN 0
#define X_MAX 120
#define Y_MAX 25

// 문자열 갯수
#define W_STRING_NUMBER 3
// 문자열 길이
#define W_STRING_LENGTH 50

struct GameTitle
{
	COORD Pos[W_STRING_NUMBER];						// 타이틀의 문자별 좌표
	wchar_t Data[W_STRING_NUMBER][W_STRING_LENGTH];	// 타이틀의 내용
} GameTitle;

struct Player
{
	COORD Pos;			// 플레이어의 좌표
} Player;

struct Bullet
{
	COORD Pos;			// 총알의 좌표
	float AliveTime;	// 총알이 나가는 시간
	bool IsShoot;		// 총알을 지금 쏘고 있는지 여부를 확인하는 값
} Bullet;

int main(void)
{
	struct GameTitle gameTitle;
	gameTitle.Data;
	wchar_t inputString[W_STRING_NUMBER][W_STRING_LENGTH] = {L"스페이스키를", L"누르면", L"다음으로 넘어갑니다."};

	for (int index = 0; index < W_STRING_NUMBER; index++) {
		wcscpy_s(gameTitle.Data[index], wcslen(inputString[index]) * 2, inputString[index]);
	}

	// 현재 화면의 핸들을 가져옴
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// 유니코드 문자를 사용하기 위해 문자의 지역을 설정
	setlocale(LC_ALL, "KOREAN");

	gameTitle.Pos[0].X = 10;
	gameTitle.Pos[0].Y = 0;
	gameTitle.Pos[1].X = gameTitle.Pos[0].X + wcslen(gameTitle.Data[0]) * 2 + 1;
	gameTitle.Pos[1].Y = 10;
	gameTitle.Pos[2].X = gameTitle.Pos[1].X + wcslen(gameTitle.Data[1]) * 2 + 1;
	gameTitle.Pos[2].Y = 20;

	while (!PRESS(VK_SPACE)) // 스페이스 바로 화면 전환
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

	// 화면 전환을 위해 입력한 스페이스바가
	// 다음 화면에 영향을 미치지 않기 위해
	// Sleep으로 잠시 멈춰줌
	Sleep(100);
	system("cls");

	// 구조체의 객체 형성
	struct Player player;
	struct Bullet bullet;

	// 사용할 변수 초기화
	player.Pos.X = 0;
	player.Pos.Y = 0;

	bullet.Pos.X = player.Pos.X;
	bullet.Pos.Y = player.Pos.Y;

	bullet.IsShoot = false;

	clock_t prevTick = 0.f;

	while (1)
	{
		// 입력부
		// 각 키의 입력을 받아 플레이어의 이동 처리
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
		// 입력부

		// 처리부
		// 사용할 변수 생성 및 초기화
		float deltatime;
		bullet.AliveTime = 0.f;
		if (bullet.IsShoot == true)
		{
			// 델타 타임 측정
			clock_t currentTick = clock();
			deltatime = (float)(currentTick - prevTick) / CLOCKS_PER_SEC;
			bullet.AliveTime += deltatime;

			// 총알의 위치 처리
			bullet.Pos.X++;

			// 현재 틱을 이전 틱으로 대입
			prevTick = currentTick;

			// 기본적으로 3초가 지나면 총알이 삭제되지만
			// 일정 화면을 넘어가도 삭제되게 만듦
			if (bullet.AliveTime >= 3.f || bullet.Pos.X == X_MAX)
			{
				bullet.IsShoot = false;
				bullet.AliveTime = 0.f;
			}
		}
		// 처리부

		// 출력부
		// 플레이어 위치에 따라 'P' 출력
		SetConsoleCursorPosition(h, player.Pos);
		putchar('P');

		// 총알을 쏘고 있다면 '0'도 출력
		if (bullet.IsShoot)
		{
			SetConsoleCursorPosition(h, bullet.Pos);
			putchar('O');
		}

		Sleep(10);
		system("cls");
		// 출력부
	}
}