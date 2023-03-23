#pragma once
#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;

#define RAD2DEG(x) (x*57.295754f)
#define DEG2RAD(x) (x*0.0174533f)
namespace NGL
{
	template <typename T> struct vector2
	{
		union
		{
			struct
			{
				T x, y;
			};
			T asArray[2];
		};

		vector2() :x(0), y(0) {
		}

		vector2(T _x, T _y) :x(_x), y(_y) {

		}

		T operator[] (int i)
		{
			return asArray[i];
		}

	};


	template <typename T> struct vector3
	{
		union
		{
			struct
			{
				T x, y, z;
			};
			T asArray[3];
		};

		vector3() :x(0), y(0), z(0) {
		}

		vector3(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {

		}

		T operator[] (int i)
		{
			return asArray[i];
		}

	};

	typedef vector2<int> vector2i;
	typedef vector2<float> vector2f;

	typedef vector3<int> vector3i;
	typedef vector3<float> vector3f;


	template<typename T> vector2<T>  operator + (const vector2<T>& a, const vector2<T>& b)
	{
		return vector2<T>(b.x + a.x, b.y + a.y);
	}

	template<typename T> vector3<T> operator + (const vector3<T>& a, const vector3<T>& b)
	{
		return vector3<T>(b.x + a.x, b.y + a.y, b.z + a.z);
	}

	vector3f operator + (const vector3f& a, const vector3i& b)
	{
		return vector3f(b.x + a.x, b.y + a.y, b.z + a.z);
	}

	vector3f operator + (const vector3i& a, const vector3f& b)
	{
		return vector3f(b.x + a.x, b.y + a.y, b.z + a.z);
	}

	vector2f operator + (const vector2f& a, const vector2i& b)
	{
		return vector2f(b.x + a.x, b.y + a.y);
	}

	vector2f operator + (const vector2i& a, const vector2f& b)
	{
		return vector2f(b.x + a.x, b.y + a.y);
	}

	template<typename T> vector2<T>  operator-(const vector2<T>& a, const vector2<T>& b)
	{
		return vector2<T>(a.x - b.x, a.y - b.y);
	}

	template<typename T> vector3<T>  operator-(const vector3<T>& a, const vector3<T>& b)
	{
		return vector3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
	}

	template<typename T> vector2f  operator*(const vector2<T>& a, float s)
	{
		return vector2f(a.x * s, a.y * s);
	}

	template<typename T> vector3f  operator*(const vector3<T>& a, float s)
	{
		return vector3f(a.x * s, a.y * s, a.z * s);
	}

	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	template<typename T> float dot(const vector2<T>& a, const vector2<T>& b)
	{
		return a.x * b.x + a.y * b.y;
	}

	template<typename T> float dot(const vector3<T>& a, const vector3<T>& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}


	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////

	template <typename T> ostream& operator<<(ostream& o, const vector2<T>& v)
	{
		o << v.x << ", " << v.y << endl;
		return o;
	}

	template <typename T> ostream& operator<<(ostream& o, const vector3<T>& v)
	{
		o << v.x << ", " << v.y << ", " << v.z << endl;
		return o;
	}

	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////

	template<typename T> float magnitude(const vector2<T>& a)
	{
		return sqrtf(a.x * a.x + a.y * a.y);
	}

	template<typename T> float magnitudeSq(const vector2<T>& a)
	{
		return dot(a, a);
	}

	template<typename T> float magnitude(const vector3<T>& a)
	{
		return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
	}

	template<typename T> float magnitudeSq(const vector3<T>& a)
	{
		return dot(a, a);
	}

	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////

	template<typename T> void normalize(vector2<T>& a)
	{
		a = a * (1.0f / magnitude(a));
	}

	template<typename T> vector2<T> normalized(vector2<T>& a)
	{
		return a * (1.0f / magnitude(a));
	}


	template<typename T> void normalize(vector3<T>& a)
	{
		a = a * (1.0f / magnitude(a));
	}

	template<typename T> vector3<T> normalized(vector3<T>& a)
	{
		return a * (1.0f / magnitude(a));
	}

	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////

	vector3f cross(const vector3f& a, const vector3f& b)
	{
		vector3f result;
		result.x = a.y * b.z - a.z * b.y;
		result.y = a.z * b.x - a.x * b.z;
		result.z = a.x * b.y - a.y * b.x;
		return result;
	}

	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////

	template<typename T> float angle(const vector2<T>& a, const vector2<T>& b)
	{
		float m = sqrtf(magnitudeSq(a) * magnitudeSq(b));
		return acosf(dot(a, b) / m);
	}

	template<typename T> float angle(const vector3<T>& a, const vector3<T>& b)
	{
		float m = sqrtf(magnitudeSq(a) * magnitudeSq(b));
		return acosf(dot(a, b) / m);
	}

	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////

	template<typename T> vector2f project(const vector2<T>& length, const vector2<T>& dir)
	{
		float m = dot(length, dir);
		float n = dot(dir, dir);
		return dir * (m / n);
	}

	template<typename T> vector3f project(const vector3<T>& length, const vector3<T>& dir)
	{
		float m = dot(length, dir);
		float n = dot(dir, dir);
		return dir * (m / n);
	}

	template<typename T> vector2f perpendicular(const vector2<T>& length, const vector2<T>& dir)
	{
		return length - project(length, dir);
	}

	template<typename T> vector3f perpendicular(const vector3<T>& length, const vector3<T>& dir)
	{
		return length - project(length, dir);
	}


	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////

	template<typename T> vector2f reflect(const vector2<T>& a, const vector2<T>& n)
	{
		return a - 2 * project(a, n);
	}

	template<typename T> vector3f reflect(const vector3<T>& a, const vector3<T>& n)
	{
		return a - 2 * project(a, n);
	}



	///////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
}
