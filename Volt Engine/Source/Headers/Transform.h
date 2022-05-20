#pragma once
#include "Vector.h"

class Transform {

private:


public:

	Transform();

	Vector Position;
	Vector Scale;
	float Rotation = 0;
};