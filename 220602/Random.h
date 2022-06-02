#pragma once
#include <time.h>
#include <stdlib.h>
#define int32 __int32

class Random
{
public:
	Random() = delete;
	~Random() = delete;
	Random(const Random&) = delete;
	Random& operator=(const Random&) = delete;

	void Init(void);
	int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive);
	float Random_GetNumberFromRange(float minInclusive, float maxInclusive);

private:
};

