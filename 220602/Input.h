#pragma once
#include <wchar.h>
#include <Windows.h>


class Input
{
public:
	#define IS_KEY_DOWN(vkey) (0x8000 & GetAsyncKeyState(vkey))
	
	Input() = delete;
	~Input() = delete;
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;
	
	void Update(void)
	{
		memcpy(this->isKeyDownOnPrevFrame, this->isKeyDownOnCurrentFrame, sizeof(this->isKeyDownOnCurrentFrame));

		for (int vkey = 0; vkey < 256; ++vkey)
		{
			if (IS_KEY_DOWN(vkey))
			{
				this->isKeyDownOnCurrentFrame[vkey] = true;
			}
			else
			{
				this->isKeyDownOnCurrentFrame[vkey] = false;
			}
		}
	}

	bool GetKeyDown(unsigned int vkey)
	{
		if (false == this->isKeyDownOnPrevFrame[vkey] && true == this->isKeyDownOnCurrentFrame[vkey])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool GetKeyUp(unsigned int vkey)
	{
		if (true == this->isKeyDownOnPrevFrame[vkey] && false == this->isKeyDownOnCurrentFrame[vkey])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool GetKey(unsigned int vkey)
	{
		if (true == this->isKeyDownOnPrevFrame[vkey] && true == this->isKeyDownOnCurrentFrame[vkey])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	static bool isKeyDownOnPrevFrame[256];
	static bool isKeyDownOnCurrentFrame[256];
};