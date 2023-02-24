#include"Vector3.h"
#include<iostream>
using namespace NGL;

Vector3 Vector3::zero = Vector3(0, 0,0);
Vector3 Vector3::one = Vector3(1, 1,1);
Vector3 Vector3::up = Vector3(0, 1,0);
Vector3 Vector3::down = Vector3(0, -1,0);
Vector3 Vector3::left = Vector3(-1, 0,0);
Vector3 Vector3::right = Vector3(1, 0,0);
Vector3 Vector3::forward = Vector3(0, 0, 1);
Vector3 Vector3::back = Vector3(0, 0, -1);

int Vector3::GetX()
{
	return this->x;
}

int Vector3::GetY()
{
	return this->x;
}

void Vector3::SetX(int _x)
{
	x = _x;
}

void Vector3::SetY(int _y)
{
	y = _y;
}

void Vector3::SetZ(int _z)
{
	z = _z;
}

int Vector3::GetZ()
{
	return z;
}

void  Vector3::Info()
{
	std::cout << "x: " << x << "	y:" << y << "	z:"<<z << std::endl;
}