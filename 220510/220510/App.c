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
		Renderer_DrawText("��Ÿ�ù� 1��", sizeof("��Ÿ�ù� 1��"));
	}

	Renderer_Flip();

	Renderer_Cleanup();
}

int App_Run(void) {
	Timer_Init();

	// ���� ���� : �Է�ó�� -> ���� ������Ʈ -> ���� ���
	while (true) {
		Timer_Update();

		processInput();
		update();
		render();
	}

	return 0;
}