#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

class Vector {
public:

	Vector();
	Vector(float x, float y);

	float Length();
	Vector& Normalize();
	Vector& Rotate(float angle);
	float Dot(Vector const& other);
	Vector operator+(Vector const& other);
	Vector operator-(Vector const& other);
	Vector operator*(Vector const& other);
	Vector operator/(Vector const& other);

	float GetX() const;
	float GetY() const;

	static Vector ZERO;
	static Vector UP;
	static Vector DOWN;
	static Vector RIGHT;
	static Vector LEFT;

private:
	float _x;
	float _y;
};