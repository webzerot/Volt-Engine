#include "../Headers/Vector.h"

Vector::Vector() : _x(0), _y(0) {}
Vector::Vector(float x, float y) : _x(x), _y(y) {}

Vector Vector::ZERO = Vector();
Vector Vector::UP = Vector(0, -1);
Vector Vector::RIGHT = Vector(1, 0);
Vector Vector::DOWN = Vector(0, 1);
Vector Vector::LEFT = Vector(-1, 0);

// check
float Vector::Length()
{
	return sqrt(pow(_x, 2) + pow(_y, 2));
}

Vector& Vector::Normalize()
{
	float length = Length();

	if (length == 0) return Vector::ZERO;

	_x /= length;
	_y /= length;

	return *this;
}

Vector& Vector::Rotate(float angle)
{
	float radians = angle * M_PI / 180;

	float cosinus = cos(radians);
	float sinus = sin(radians);

	float x = _x * cosinus - _y * sinus;
	float y = _x * sinus + _y * cosinus;

	_x = x;
	_y = y;

	return *this;
}

float Vector::Dot(Vector const& other)
{
	float x = _x * other.GetX();
	float y = _y * other.GetY();
	return x + y;
}

Vector Vector::operator+(Vector const& other)
{
	float x = _x + other.GetX();
	float y = _y + other.GetY();
	return Vector(x, y);
}

Vector Vector::operator-(Vector const& other)
{
	float x = _x - other.GetX();
	float y = _y - other.GetY();
	return Vector(x, y);
}

Vector Vector::operator*(Vector const& other)
{
	float x = _x * other.GetX();
	float y = _y * other.GetY();
	return Vector(x, y);
}

Vector Vector::operator/(Vector const& other)
{
	float x = _x / other.GetX();
	float y = _y / other.GetY();
	return Vector(x, y);
}

float Vector::GetX() const { return _x; }
float Vector::GetY() const { return _y; }
