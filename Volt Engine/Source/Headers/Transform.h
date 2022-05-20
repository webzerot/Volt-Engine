#pragma once
#include "Vector.h"
#include <SFML/Graphics.hpp>

class Transform {

private:


public:

	Transform();

	Vector Position;
	Vector Scale;
	float Rotation = 0;

};