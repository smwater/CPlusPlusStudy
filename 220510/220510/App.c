#include "App.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Timer.h"
#include "Renderer.h"

bool App_Init(void) {
	if (false == Renderer_Init()) {
		return false;
	}

	return true;
}

void processInput(void) {
	
}

char str[128];
bool canShow = false;
float elapsedTime;

void update(void) {
	Sleep(10);

	elapsedTime += Timer_GetDeltaTime();
	if (elapsedTime >= 0.5f) {
		elapsedTime = 0.0f;
		canShow = !canShow;
	}
}

void render(void) {
	if (canShow) {
		Renderer_DrawText("메타플밍 1기", sizeof("메타플밍 1기"));
	}

	Renderer_Flip();

	Renderer_Cleanup();
}

int App_Run(void) {
	Timer_Init();

	// 게임 루프 : 입력처리 -> 게임 업데이트 -> 게임 출력
	while (true) {
		Timer_Update();

		processInput();
		update();
		render();
	}

	return 0;
}