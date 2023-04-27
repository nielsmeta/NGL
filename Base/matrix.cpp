#include"matrix.h"

#include<cmath>
#include<cfloat>

void transpose(const float* src, float* dest, int srcRow, int srcCol)
{
	for (int i = 0; i < srcRow * srcCol; i++)
	{
		int row = i / srcRow;
		int col = i % srcRow;
		dest[i] = src[srcCol * col + row];
	}
}

matrix2x2 transpose(const matrix2x2& mat2)
{
	matrix2x2 p;
	transpose(mat2.toArray, p.toArray, 2, 2);
	return p;
}

matrix2x2 operator*(const matrix2x2& mat2, float s)
{
	matrix2x2 p;
	for (int i = 0; i < 4; i++)
	{
		p.toArray[i] = mat2.toArray[i] * s;
	}
	return p;
}

matrix2x2 operator*(const matrix2x2& mat1, const matrix2x2 mat2)
{
	matrix2x2 re;
	mul(re.toArray, mat1.toArray, 2, 2, mat2.toArray, 2, 2);
	return re;
}

vector2 mul(const matrix2x2 mat, const vector2& v)
{
	vector2 result = vector2(mat._11 * v.x + mat._12 * v.y, mat._21 * v.x + mat._22 * v.y);
	return result;
}

bool mul(float* out, const float* mat1, int row1, int col1, const float* mat2, int row2, int col2)
{
	if (col1 != row2)
	{
		return false;
	}

	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col2; j++)
		{
			out[i * col2 + j] = 0.0f;
			for (int k = 0; k < row2; ++k) {
				int a = col1 * i + k;
				int b = col2 * k + j;
				out[col2 * i + j] += mat1[a] * mat2[b];
			}
		}
	}

	return true;
}

matrix2x2 mul(const matrix2x2& mat1, const matrix2x2 mat2)
{
	matrix2x2 re;
	mul(re.toArray, mat1.toArray, 2, 2, mat2.toArray, 2, 2);
	return re;
}

float  determinant(const matrix2x2& mat)
{
	return mat._11 * mat._22 - mat._12 * mat._21;
}

matrix2x2 minor(const matrix2x2& mat)
{
	return matrix2x2(mat._22, mat._21,
		mat._12, mat._11);
}


void cofactor(float* out, const float* minor, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int index = cols * j + i;
			float sign = pow(-1, (i + j));
			out[index] = minor[index] * sign;
		}
	}
}

matrix2x2 adjugate(const matrix2x2& mat)
{
	return transpose(cofactor(mat));
}


matrix2x2 cofactor(const matrix2x2& mat)
{
	matrix2x2 re;
	cofactor(re.toArray, minor(mat).toArray, 2, 2);
	return re;
}

matrix2x2 inverse(const matrix2x2& mat)
{
	float det = determinant(mat);
	if (CMP(det, 0.0f))
	{
		return matrix2x2();
	}
	return adjugate(mat) * (1.0f / det);
}

ostream& operator<<(ostream& o, const matrix2x2 mat)
{
	o << endl;
	o << "	" << mat._11 << " " << mat._12 << '\n'
		<< "	" << mat._21 << " " << mat._22;
	o << endl;
	return o;
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

matrix3x3 transpose(const matrix3x3& mat3)
{
	matrix3x3 p;
	transpose(mat3.toArray, p.toArray, 3, 3);
	return p;
}

matrix3x3 operator*(const matrix3x3& mat2, float s)
{
	matrix3x3 p;
	for (int i = 0; i < 9; i++)
	{
		p.toArray[i] = mat2.toArray[i] * s;
	}
	return p;
}


matrix3x3 operator*(const matrix3x3& mat1, const matrix3x3& mat2)
{
	matrix3x3 re;
	mul(re.toArray, mat1.toArray, 3, 3, mat2.toArray, 3, 3);
	return re;
}

matrix3x3 mul(const matrix3x3& mat1, const matrix3x3 mat2)
{
	matrix3x3 re;
	mul(re.toArray, mat1.toArray, 3, 3, mat2.toArray, 3, 3);
	return re;
}

vector3 mul(const matrix3x3& mat, const vector3& v)
{
	vector3 re;
	re.x = mat._11 * v.x + mat._12 * v.y + mat._13 * v.z;
	re.y = mat._21 * v.x + mat._22 * v.y + mat._23 * v.z;
	re.z = mat._31 * v.x + mat._32 * v.y + mat._23 * v.z;
	return re;
}

float determinant(const matrix3x3& mat)
{
	//按照行展开
	/*return mat._11 * determinant(matrix2x2(mat._22, mat._23, mat._32, mat._33)) -
		mat._12 * determinant(matrix2x2(mat._21, mat._23, mat._31, mat._33)) +
		mat._13 * determinant(matrix2x2(mat._21, mat._22, mat._31, mat._32));*/
	float re = 0.0f;
	matrix3x3 cof = cofactor(mat);
	for (int j = 0; j < 3; j++)
	{
		re += mat.toArray[j] * cof[0][j];//?这里似乎有问题，待查
	}
	return re;
}

matrix2x2  cut(const matrix3x3& mat, int row, int col)
{
	matrix2x2 result;
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == row || j == col)
				continue;
			int target = index++;
			result.toArray[target] = mat.toArray[3 * i + j];
		}
	}
	return result;
}


matrix3x3 minor(const matrix3x3& mat)
{
	matrix3x3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = determinant(cut(mat, i, j));
		}
	}

	return result;
}


matrix3x3 cofactor(const matrix3x3& mat)
{
	matrix3x3 re;
	cofactor(re.toArray, minor(mat).toArray, 3, 3);
	return re;
}

matrix3x3 adjugate(const matrix3x3& mat)
{
	return transpose(cofactor(mat));
}

matrix3x3 inverse(const matrix3x3& mat)
{
	float det = determinant(mat);
	if (CMP(det, 0.0f))
	{
		return matrix3x3();
	}
	return adjugate(mat) * (1.0f / det);
}

ostream& operator<<(ostream& o, const matrix3x3 mat)
{
	o << endl;
	o << "	" << mat._11 << " " << mat._12 << " " << mat._13
		<< "	" << mat._21 << " " << mat._22 << " " << mat._23
		<< "	" << mat._31 << " " << mat._32 << " " << mat._33 << endl;
	return o;
}


matrix4x4 transpose(const matrix4x4& mat4)
{
	matrix4x4 p;
	transpose(mat4.toArray, p.toArray, 4, 4);
	return p;
}

matrix4x4 operator*(const matrix4x4& mat2, float s)
{
	matrix4x4 p;
	for (int i = 0; i < 16; i++)
	{
		p.toArray[i] = mat2.toArray[i] * s;
	}
	return p;
}

matrix4x4 operator*(const matrix4x4& mat1, const matrix4x4& mat2)
{
	matrix4x4 re;
	mul(re.toArray, mat1.toArray, 4, 4, mat2.toArray, 4, 4);
	return re;
}

matrix4x4 mul(const matrix4x4& mat1, const matrix4x4 mat2)
{
	matrix4x4 re;
	mul(re.toArray, mat1.toArray, 4, 4, mat2.toArray, 4, 4);
	return re;
}

matrix3x3 cut(const matrix4x4& mat, int row, int col)
{
	int index = 0;
	matrix3x3 re;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (row == i || j == col)
				continue;
			int target = index++;
			int source = 4 * i + j;
			re.toArray[target] = mat.toArray[source];
		}
	}
	return re;
}

matrix4x4 minor(const matrix4x4& mat)
{
	matrix4x4 re;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			re[i][j] = determinant(cut(mat, i, j));
		}
	}
	return re;
}

matrix4x4 cofactor(const matrix4x4& mat)
{
	matrix4x4 re;
	auto min = minor(mat);
	cofactor(re.toArray, min.toArray, 4, 4);
	return re;
}

float determinant(const matrix4x4& mat)
{
	float re = 0.0f;
	auto factor = cofactor(mat);
	for (int j = 0; j < 4; j++)
	{
		re += mat.toArray[j] * factor[0][j];
	}
	return re;
}

matrix4x4 adjugate(const matrix4x4& mat)
{
	return transpose(cofactor(mat));
}

matrix4x4 inverse(const matrix4x4& mat)
{
	float det = determinant(mat);
	if (CMP(det, 0.0f))
	{
		return matrix4x4();
	}
	return adjugate(mat) * (1.0f / det);
}


matrix4x4 translate(float x, float y, float z)
{
	matrix4x4 re = matrix4x4();
	re._41 = x;
	re._42 = y;
	re._43 = z;
	return re;
}

matrix4x4 translate(const vector3& vec)
{
	matrix4x4 re = matrix4x4();
	re._41 = vec.x;
	re._42 = vec.y;
	re._43 = vec.z;
	return re;
}

vector3 getTranslation(const matrix4x4& mat)
{
	return vector3(mat._41, mat._42, mat._43);
}


matrix4x4 scale(float x, float y, float z)
{
	matrix4x4 re = matrix4x4();
	re._11 = x;
	re._22 = y;
	re._33 = z;
	return re;
}

matrix4x4 scale(const vector3 vec)
{
	matrix4x4 re = matrix4x4();
	re._11 = vec.x;
	re._22 = vec.y;
	re._33 = vec.z;
	return re;
}

vector3 getScale(const matrix4x4& mat)
{
	return vector3(mat._11, mat._22, mat._33);
}

matrix4x4 zRotation(float angle)
{
	angle = DEG2RAD(angle);
	return matrix4x4(cosf(angle), sinf(angle), 0.0f, 0.0,
		-sinf(angle), cosf(angle), 0.0, 0.0,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

matrix4x4 yRotation(float angle)
{
	angle = DEG2RAD(angle);
	return matrix4x4(cosf(angle), 0.0f, -sinf(angle), 0.0,
		0.0f, 1.0f, 0.0f, 0.0f,
		sinf(angle), 0.0f, cosf(angle), 0.0f,
		0.0f, 0.0, 0.0f, 1.0f
	);
}

matrix4x4 xRotation(float angle)
{
	angle = DEG2RAD(angle);
	return matrix4x4(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosf(angle), sinf(angle), 0.0,
		0.0, -sinf(angle), cosf(angle), 0.0,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

matrix3x3 zRotation3x3(float angle)
{
	angle = DEG2RAD(angle);
	return matrix3x3(cosf(angle), sinf(angle), 0.0f,
		-sinf(angle), cosf(angle), 0.0,
		0.0f, 0.0f, 1.0f
	);
}

matrix3x3 yRotation3x3(float angle)
{
	angle = DEG2RAD(angle);
	return matrix3x3(cosf(angle), 0.0f, -sinf(angle),
		0.0f, 1.0f, 0.0f,
		sinf(angle), 0.0f, cosf(angle)
	);
}

matrix3x3 xRotation3x3(float angle)
{
	angle = DEG2RAD(angle);
	return matrix3x3(1.0f, 0.0f, 0.0f,
		0.0f, cosf(angle), sinf(angle),
		0.0, -sinf(angle), cosf(angle)
	);
}

matrix4x4 rotation(float roll, float pitch, float yaw)
{
	return zRotation(roll) * xRotation(pitch) * yRotation(yaw);
}

vector3 mulPoint(const vector3& p, const matrix4x4& mat)
{
	vector3 re;
	re.x = p.x * mat._11 + p.y * mat._12 + p.z * mat._13 + 1.0f * mat._14;
	re.y = p.x * mat._21 + p.y * mat._22 + p.z * mat._23 + 1.0f * mat._24;
	re.z = p.x * mat._31 + p.y * mat._32 + p.z * mat._33 + 1.0f * mat._34;
	return re;
}

vector3 mulVector(const vector3& v, const matrix4x4& mat)
{
	vector3 re;
	re.x = v.x * mat._11 + v.y * mat._12 + v.z * mat._13;
	re.y = v.x * mat._21 + v.y * mat._22 + v.z * mat._23;
	re.z = v.x * mat._31 + v.y * mat._32 + v.z * mat._33;
	return re;
}

matrix4x4 transform(const vector3& s, const vector3& r, const vector3& t)
{
	//先缩放、再旋转、最后平移
	return   translate(t) * scale(s) * rotation(r.x, r.y, r.z);
}

matrix4x4 lookAt(vector3& position, const vector3& target, const vector3& up)
{
	vector3 forward = normalize(target - position);
	vector3 right = normalize(cross(up, forward));
	vector3 newUp = cross(forward, right);
	float _14 = right.x * position.x + right.y * position.y + right.z * position.z;
	float _24 = newUp.x * position.x + newUp.y * position.y + newUp.z * position.z;
	float _34 = forward.x * position.x + forward.y * position.y + forward.z * position.z;
	return matrix4x4(
		right.x, right.y, right.z, -_14,
		newUp.x, newUp.y, newUp.z, -_24,
		forward.x, forward.y, forward.z, -_34,
		0, 0, 0, 1.0f
	);
}


/// <summary>
/// 正交变换矩阵
/// </summary>
/// <param name="left"></param>
/// <param name="right"></param>
/// <param name="top"></param>
/// <param name="bottom"></param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
matrix4x4 ortho(float left, float right, float top, float bottom, float near, float far)
{
	matrix4x4 result;
	result._11 = 2.0f / (right - left);
	result._22 = 2.0f / (top - bottom);
	result._33 = 2.0f / (near - far);
	result._14 = -(left + right) / 2;
	result._24 = -(top + bottom) / 2;
	result._34 = -(near + far) / 2;
	return result;
}



/// <summary>
/// 透视投影矩阵
/// </summary>
/// <param name="fov"></param>
/// <param name="aspect"></param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
matrix4x4 perspective(float fov, float aspect, float near, float far)
{
	float tanHalfRad = tanf(DEG2RAD(fov * 0.5f));
	float top = (far - near) * tanHalfRad;
	float bottom = -top;
	float right = top * aspect;
	float left = - right;
	matrix4x4 re;
	re._11 = 2 * near * (right - left);
	re._13 = (left + right);
	return re;
}