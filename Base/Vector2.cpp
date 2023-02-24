#include"Vector2.h"
#include<iostream>
using namespace NGL;

Vector2 Vector2::zero = Vector2(0, 0);
Vector2 Vector2::one = Vector2(1, 1);
Vector2 Vector2::up = Vector2(0, 1);
Vector2 Vector2::down = Vector2(0, -1);
Vector2 Vector2::left = Vector2(-1, 0);
Vector2 Vector2::right = Vector2(1, 0);
int Vector2::GetX()
{
	return this->x;
}

int Vector2::GetY()
{
	return this->x;
}

void Vector2::SetX(int _x)
{
	x = _x;
}

void Vector2::SetY(int _y)
{
	y = _y;
}

void  Vector2::Info()
{
	std::cout << "x: " << x << "	y:" << y << std::endl;
}