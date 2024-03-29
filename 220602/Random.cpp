#include "Random.h"

void Random::Init(void)
{
	srand(time(NULL));
}

int32 Random::Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive)
{
	float normalizedRandom = rand() / (float)(RAND_MAX - 1);
	int32 range = maxExclusive - minInclusive;
	int32 result = minInclusive + normalizedRandom * range;

	return result;
}

float Random::Random_GetNumberFromRange(float minInclusive, float maxInclusive)
{
	float normalizedRandom = rand() / (float)RAND_MAX;
	float range = maxInclusive - minInclusive;
	float result = minInclusive + normalizedRandom * range;

	return result;
}