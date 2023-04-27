#pragma once
#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;

#define RAD2DEG(x) (x*57.295754f)
#define DEG2RAD(x) (x*0.0174533f)
#define CMP(x,y)  \
	(fabsf((x) - (y)) <= FLT_EPSILON * fmaxf(1.0f, fmaxf(fabsf(x),fabsf(y))))

struct vector2
{
	union {
		struct 
		{
			float x, y;
		};

		float arrays[2];
	};

	inline float operator[](int i)
	{
		return arrays[i];
	}


	vector2();
	vector2(float x, float y);
};

struct vector3
{
	union
	{
		struct 
		{
			float x, y, z;
		};

		float arrays[3];
	};

	inline float operator[](int i)
	{
		return arrays[i];
	}

	vector3();
	vector3(float x, float y,float z);
};

vector2  operator+ (const vector2& a, const vector2& b);
vector3 operator+ (const vector3& a, const vector3& b);

vector2  operator- (const vector2& a, const vector2& b);
vector3 operator- (const vector3& a, const vector3& b);

vector2 operator*(const vector2& a, float s);
vector3 operator*(const vector3& a, float s);

vector2 operator*(float s,const vector2& a);
vector3 operator*(float s,const vector3& a);

ostream& operator<< (ostream& o, const vector2& a);
ostream& operator<< (ostream& o, const vector3& a);

float dot(const vector2& a, const vector2& b);

float dot(const vector3& a, const vector3& b);

float magnitude(const vector2& a);
float magnitude(const vector3& a);

float sqrMagnitude(const vector2& a);
float sqrMagnitude(const vector3& a);

vector2 normalize(const vector2& a);

void normalized(vector2& a);

vector3 normalize(const vector3& a);

void normalized(vector3& a);

vector3 cross(const vector3& a, const vector3& b);

float angle(const vector2& a, const vector2& b);
float angle(const vector3& a, const vector3& b);

vector3 project(const vector3& a, const vector3& b);

vector3 perPendicular(const vector3& a, const vector3& b);

vector2 project(const vector2& a, const vector2& b);

vector2 perPendicular(const vector2& a, const vector2& b);

vector2 reflect(const vector2& a, const vector2& normal);
vector3 reflect(const vector3& a, const vector3& normal);

