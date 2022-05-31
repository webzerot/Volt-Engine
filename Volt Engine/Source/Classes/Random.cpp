#include "../Headers/Random.h"
#include <random>


int Random::Range_Int(int min, int max) {
	int range = max - min + 1;
	int num = rand() % range + min;

	return num;
}