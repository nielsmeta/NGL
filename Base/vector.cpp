#include"vector.h"



vector2::vector2() :x(0),y(0)
{

}

vector2::vector2(float x, float y) : x(x), y(y)
{

}

vector3::vector3() : x(0), y(0),z(0)
{

}

vector3::vector3(float x, float y,float z) : x(x), y(y),z(z)
{

}

vector2  operator+ (const vector2& a, const vector2& b)
{
	return vector2(a.x + b.x, a.y + b.y);
}

vector3 operator+ (const vector3& a, const vector3& b)
{
	return vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vector2  operator- (const vector2& a, const vector2& b)
{
	return vector2(a.x - b.x, a.y - b.y);
}

vector3 operator- (const vector3& a, const vector3& b)
{
	return vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

vector2 operator*(const vector2& a, float s)
{
	return vector2(a.x * s, a.y * s);
}

vector3 operator*(const vector3& a, float s)
{
	return vector3(a.x * s, a.y * s, a.z * s);
}

vector2 operator*(float s, const vector2& a)
{
	return a * s;
}
vector3 operator*(float s, const vector3& a)
{
	return a * s;
}

ostream& operator<< (ostream& o, const vector2& a)
{
	o << a.x << ',' << a.y << endl;
	return o;
}

ostream& operator<< (ostream& o, const vector3& a)
{
	o << a.x << ',' << a.y << ',' << a.z << endl;
	return o;
}

float dot(const vector2& a, const vector2& b)
{
	return  a.x * b.x + a.y * b.y;
}

float dot(const vector3& a, const vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z* b.z;
}

float magnitude(const vector2& a)
{
	return sqrtf(dot(a, a));
}

float magnitude(const vector3& a)
{
	return sqrtf(dot(a, a));
}

float sqrMagnitude(const vector2& a)
{
	return dot(a, a);
}

float sqrMagnitude(const vector3& a)
{
	return dot(a, a);
}

vector2 normalize(const vector2& a)
{
	return a * (1.0f / magnitude(a));
}

void normalized(vector2& a)
{
	float l = (1.0f*magnitude(a));
	a.x *= l;
	a.y *= l;
}

vector3 normalize(const vector3& a)
{
	return a * (1.0f / magnitude(a));
}

void normalized(vector3& a)
{
	float l = (1.0f * magnitude(a));
	a.x *= l;
	a.y *= l;
	a.z *= l;
}

vector3 cross(const vector3& a, const vector3& b)
{
	vector3 re;
	re.x = a.y * b.z - a.z * b.y;
	re.y = b.z * a.x - a.z * b.x;
	re.z = a.x * b.y - a.y * b.x;
	return re;
}

float angle(const vector2& a, const vector2& b)
{
	float m = sqrtf(sqrMagnitude(a) * sqrMagnitude(b));
	return acosf(dot(a, b) / m);
}

float angle(const vector3& a, const vector3& b)
{
	float m = sqrtf(sqrMagnitude(a) * sqrMagnitude(b));
	return acosf(dot(a, b) / m);
}

vector3 project(const vector3& a, const vector3& b)
{
	float m = dot(a, b);
	float n = dot(b, b);
	return normalize(b) * (m / n);
}

vector3 perPendicular(const vector3& a, const vector3& b)
{
	return a - project(a, b);
}

vector2 project(const vector2& a, const vector2& b)
{
	float m = dot(a, b);
	float n = dot(b, b);
	return normalize(b) * (m / n);
}

vector2 perPendicular(const vector2& a, const vector2& b)
{
	return a - project(a, b);
}


vector2 reflect(const vector2& a, const vector2& normal)
{
	vector2 n = normalize(normal);
	return  a - 2 * project(a, n);
}
vector3 reflect(const vector3& a, const vector3& normal)
{
	vector3 n = normalize(normal);
	return  a - 2 * project(a, n);
}