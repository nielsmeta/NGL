#pragma once
#ifndef __VECTOR__H
#define __VECTOR__H
#include<iostream>
using namespace std;


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

	vector2<T> operator+(const vector2<T>& a);
	vector2<T> operator-(const vector2 <T>& a);
	vector2<T> operator*(float s);
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

template <typename T> struct vector4
{
	union
	{
		struct
		{
			T x, y, z, w;
		};
		T asArray[4];
	};

	vector4() :x(0), y(0), z(0), w(0) {
	}

	vector4(T _x, T _y, T _z, T _w) :x(_x), y(_y), z(_z), w(_w) {

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

typedef vector4<int> vector4i;
typedef vector4<float> vector4f;


template<typename T> vector2<T>  vector2<T>::operator + (const vector2<T>& a)
{
	return vector2<T>(this->x + a.x, this->y + a.y);
}

template<typename T> vector2<T>  vector2<T>::operator-(const vector2 <T>& a)
{
	return vector2<T>(this->x - a.x, this->y - a.y);
}

template<typename T> vector2<T>  vector2<T>::operator*(float s)
{
	return vector2<T>(this->x*s, this->y *s);
}

template<typename T> float dot(const vector2<T>& a, const vector2<T>b)
{
	return a.x * b.x + a.y * b.y;
}

template < typename T> ostream& operator<<(ostream& o, const vector2<T>& v) 
{
	o << v.x <<", " << v.y << endl;
	return o;
}


#endif // !__VECTOR__H
