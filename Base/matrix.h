#pragma once

#include"vector.h"
#include<iostream>
using namespace std;




typedef struct matrix2x2
{
	union
	{

		struct
		{
			float _11, _12,
				_21, _22;

		};
		float toArray[4];
	};
	inline float* operator[](int index)
	{
		return &(toArray[index * 2]);
	}

	inline matrix2x2()
	{
		_11 = _22 = 1.0f;
		_12 = _21 = 0.0f;
	}


	inline matrix2x2(float f11, float f12, float f21, float f22
	)
	{
		_11 = f11, _12 = f12;
		_21 = f21, _22 = f22;
	}

}matrix2x2;

typedef struct matrix3x3
{

	union
	{
		struct
		{
			float _11, _12, _13,
				_21, _22, _23,
				_31, _32, _33;
		};
		float toArray[9];
	};

	inline float* operator[](int index)
	{
		return &(toArray[index * 3]);
	}

	inline matrix3x3()
	{
		_11 = _22 = _33 = 1.0f;
		_12 = _13 = _21 = _23 = _31 = _32 = 0.0f;
	}

	inline matrix3x3(float f11, float f12, float f13, float f21, float f22, float f23,
		float f31, float f32, float f33
	)
	{
		_11 = f11, _12 = f12, _13 = f13;
		_21 = f21, _22 = f22, _23 = f23;
		_31 = f31, _32 = f32, _33 = f33;
	}

}matrix3x3;

typedef struct matrix4x4
{
	union
	{
		struct
		{
			float _11, _12, _13, _14,
				_21, _22, _23, _24,
				_31, _32, _33, _34,
				_41, _42, _43, _44;

		};
		float toArray[16];

	};
	inline float* operator[](int index)
	{
		return &(toArray[index * 4]);
	}

	inline matrix4x4()
	{
		_11 = _22 = _33 = _44 = 1.0f;
		_12 = _13 = _14 =
			_21 = _23 = _24 =
			_31 = _32 = _34 =
			_41 = _42 = _43 = 0.0f;
	}
	inline matrix4x4(float f11, float f12, float f13, float f14, float f21, float f22, float f23, float f24,
		float f31, float f32, float f33, float f34, float f41, float f42, float f43, float f44
	)
	{
		_11 = f11, _12 = f12, _13 = f13, _14 = f14;
		_21 = f21, _22 = f22, _23 = f23, _24 = f24;
		_31 = f31, _32 = f32, _33 = f33, _34 = f34;
		_41 = f41, _42 = f42, _43 = f43, _44 = f44;
	}
}matrix4x4;

/// <summary>
/// ����ͶӰ����
/// </summary>
/// <param name="left"></param>
/// <param name="right"></param>
/// <param name="top"></param>
/// <param name="bottom"></param>
/// <param name="near"></param>
/// <param name="far"></param>
/// <returns></returns>
matrix4x4 ortho(float left, float right, float top, float bottom, float near, float far);

/// <summary>
/// ͸��ͶӰ
/// </summary>
/// <param name="fov"></param>
/// <param name="aspect"></param>
/// <param name="near"></param>
/// <param name="far"></param>
/// <returns></returns>
matrix4x4 perspective(float fov, float aspect, float near, float far);

ostream& operator<<(ostream& o, const matrix4x4 mat);

void transpose(const float* src, float* dest, int srcRow, int srcCol);
matrix2x2 transpose(const matrix2x2& mat2);

matrix2x2 operator*(const matrix2x2& mat2, float s);

matrix2x2 operator*(const matrix2x2& v, const matrix2x2 mat);

vector2 mul(const matrix2x2 mat,const vector2& v);

bool mul(float* out, const float* mat1, int row1, int col1, const float* mat2, int row2, int col2);

matrix2x2 mul(const matrix2x2& mat1, const matrix2x2 mat2);

/// <summary>
/// ���׾�������ʽ
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
float  determinant(const matrix2x2& mat);

/// <summary>
/// ����ʽ����
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix2x2 minor(const matrix2x2& mat);

matrix2x2 cofactor(const matrix2x2& mat);

/// <summary>
/// ���������ʽ������ɵľ���
/// </summary>
/// <param name="out">����Ľ��</param>
/// <param name="minor">����ʽ</param>
/// <param name="rows">����ʽ����</param>
/// <param name="cols">����ʽ����</param>
void cofactor(float* out, const float* minor, int rows, int cols);

/// <summary>
/// �������
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix2x2 adjugate(const matrix2x2& mat);

/// <summary>
/// �������
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix2x2 inverse(const matrix2x2& mat);

matrix2x2 rotation(float angle);

ostream& operator<<(ostream& o, const matrix2x2 mat);


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

matrix3x3 transpose(const matrix3x3& mat2);

matrix3x3 operator*(const matrix3x3& mat2, float s);

matrix3x3 operator*(const matrix3x3& mat1, const matrix3x3& mat2);

matrix3x3 mul(const matrix3x3& mat1, const matrix3x3 mat2);

vector3 mul(const matrix3x3& mat, const vector3& v);

/// <summary>
/// ��������ʽ
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
float determinant(const matrix3x3& mat);


/// <summary>
/// 3x3����ȥ��ĳ��ĳ��
/// </summary>
/// <param name="mat">��Ҫ�ü��ľ���</param>
/// <param name="row">Ҫ�ü�����</param>
/// <param name="col">Ҫ�ü�����</param>
/// <returns>�ü����2x2����</returns>
matrix2x2 cut(const matrix3x3& mat, int row, int col);

/// <summary>
/// 3x3��������ʽ
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix3x3 minor(const matrix3x3& mat);

/// <summary>
/// ϵ����������ʽ
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix3x3 cofactor(const matrix3x3& mat);

/// <summary>
/// ��������
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix3x3 adjugate(const matrix3x3& mat);

/// <summary>
/// 3x3����������
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix3x3 inverse(const matrix3x3& mat);

ostream& operator<<(ostream& o, const matrix3x3 mat);

matrix4x4 transpose(const matrix4x4& mat4);

matrix4x4 operator*(const matrix4x4& mat2, float s);

matrix4x4 operator*(const matrix4x4& mat1, const matrix4x4& mat2);


matrix4x4 mul(const matrix4x4& mat1, const matrix4x4 mat2);

/// <summary>
/// 4��ȥ��ĳһ��ĳһ��
/// </summary>
/// <param name="mat"></param>
/// <param name="row"></param>
/// <param name="col"></param>
/// <returns></returns>
matrix3x3 cut(const matrix4x4& mat, int row, int col);

/// <summary>
/// 4�׾�������ʽ����
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix4x4 minor(const matrix4x4& mat);


/// <summary>
/// 4��ϵ������
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix4x4 cofactor(const matrix4x4& mat);

/// <summary>
/// 4�׾�������ʽ
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
float determinant(const matrix4x4& mat);

/// <summary>
/// �������
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix4x4 adjugate(const matrix4x4& mat);

/// <summary>
/// �������
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
matrix4x4 inverse(const matrix4x4& mat);

/// <summary>
/// ƽ�ƾ���
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <returns></returns>
matrix4x4 translate(float x, float y, float z);


matrix4x4 translate(const vector3& vec);

/// <summary>
/// ��ȡһ�������ƽ��ֵ
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
vector3 getTranslation(const matrix4x4& mat);

/// <summary>
/// ���ž���
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <returns></returns>
matrix4x4 scale(float x, float y, float z);

matrix4x4 scale(const vector3 vec);

/// <summary>
/// ��ȡ����ֵ
/// </summary>
/// <param name="mat"></param>
/// <returns></returns>
vector3 getScale(const matrix4x4& mat);

/// <summary>
/// 4��z����ת
/// </summary>
/// <param name="angle"></param>
/// <returns></returns>
matrix4x4 zRotation(float angle);

/// <summary>
/// 4����y����ת
/// </summary>
/// <param name="angle"></param>
/// <returns></returns>
matrix4x4 yRotation(float angle);

/// <summary>
/// 4����x����ת
/// </summary>
/// <param name="angle"></param>
/// <returns></returns>
matrix4x4 xRotation(float angle);

/// <summary>
/// 3��z����ת����
/// </summary>
/// <param name="angle"></param>
/// <returns></returns>
matrix3x3 zRotation3x3(float angle);

/// <summary>
/// 3��y����ת����
/// </summary>
/// <param name="angle"></param>
/// <returns></returns>
matrix3x3 yRotation3x3(float angle);

/// <summary>
/// 3��z����ת����
/// </summary>
/// <param name="angle"></param>
/// <returns></returns>
matrix3x3 xRotation3x3(float angle);

/// <summary>
/// first rotate around z axis, then x axis, finally y axis
/// </summary>
/// <param name="roll"></param>
/// <param name="pitch"></param>
/// <param name="yaw"></param>
/// <returns></returns>
matrix4x4 rotation(float roll, float pitch, float yaw);

vector3 mulPoint(const matrix4x4& mat, const vector3& p);

vector3 mulVector(const matrix4x4& mat, const vector3& v);

//�����š�����ת�����ƽ��
matrix4x4 transform(const vector3& scale, const vector3& rotation, const vector3& translate);

/// <summary>
/// ��ͼ��ת����
/// </summary>
/// <param name="position"></param>
/// <param name="target"></param>
/// <param name="up"></param>
/// <returns></returns>
matrix4x4 lookAt(const vector3& position, const vector3& target, const vector3& up);


/// <summary>
/// opengl ����ͶӰ����
/// near is less than far
/// both near and far are positive value
/// </summary>
/// <param name="left"></param>
/// <param name="right"></param>
/// <param name="top"></param>
/// <param name="bottom"></param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
matrix4x4 glOrtho(float left, float right, float top, float bottom, float near, float far);

/// <summary>
/// opengl ͸��ͶӰ����
/// near is less than far value
/// both near and far are positive value
/// </summary>
/// <param name="fov"></param>
/// <param name="aspect"></param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
matrix4x4 glPerspective(float fov, float aspect, float near, float far);
