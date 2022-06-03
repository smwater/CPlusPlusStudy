#pragma once
#include <Windows.h>
#include "Text.h"
#define int16 __int16

class Bullet
{
public:
	void SetCoord(int x, int y)
	{
		this->Coord.X = x;
		this->Coord.Y = y;
	}

	Bullet(struct tagGun* gun, int16 color)
	{
		SetCoord(0, 0);
		this->ElapsedTimeForMove = 0.0f;
		this->IsActive = false;
		this->ActiveTime = 3.0f;
		TextCopy(this->Text, L"¡Û", color);
		this->Gun = gun;

	}

	void Update()
	{
		if (false == this->IsActive)
		{
			return;
		}

		this->ElapsedTimeForMove += Timer_GetDeltaTime();
		if (this->ElapsedTimeForMove >= 0.05f)
		{
			this->ElapsedTimeForMove = 0.0f;

			++this->Coord.X;
		}

		this->ActiveTime += Timer_GetDeltaTime();
		if (this->ActiveTime >= 3.0f)
		{
			this->ActiveTime = 0.0f;
			this->IsActive = false;
			--this->Gun->BulletCount;
		}
	}

	void Render()
	{
		if (false == this->IsActive)
		{
			return;
		}

		Text* text = &this->Text;
		Renderer_DrawText(text, 1, this->Coord.X, this->Coord.Y);
	}

	void Release()
	{

	}

	void Spawn(int32 x, int32 y)
	{
		this->ActiveTime = true;
		this->Coord.X = x;
		this->Coord.Y = y;
	}


private:
	bool	IsActive;
	COORD	Coord;
	float	ActiveTime;
	float	ElapsedTimeForMove;
	Text	Text;
	struct tagGun* Gun;
};

