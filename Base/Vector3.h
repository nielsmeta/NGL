#pragma once
namespace NGL
{
	class Vector3
	{
	public:

		int GetX();
		int GetY();
		int GetZ();

		void SetX(int _x);
		void SetY(int _y);
		void SetZ(int _z);

		void Info();

		static Vector3 Zero()
		{
			return zero;
		}

		static Vector3 One()
		{
			return one;
		}

		static Vector3 Up()
		{
			return up;
		}

		static Vector3 Down()
		{
			return down;
		}

		Vector3 operator + (Vector3  other)
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}
		Vector3 operator - (Vector3 other)
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}

		void operator = (Vector3 other)
		{
			x = other.x;
			y = other.y;
		}

		

		bool operator == (Vector3 other)
		{
			return x == other.x && y == other.y;
		}

		bool operator != (Vector3 other)
		{
			return !(*this == other);
		}

		void operator += (Vector3 other)
		{
			*this = (*this + other);
		}

		void operator -= (Vector3 other)
		{
			*this = (*this - other);
		}

		

		Vector3(int _x, int _y,int _z)
		{
			x = _x;
			y = _y;
			z = _z;
		}

		Vector3()
		{
			x = y = z = 0;
		}

	private:
		int x, y, z;
		static Vector3 zero;
		static Vector3 one;
		static Vector3 up;
		static Vector3 down;
		static Vector3 left;
		static Vector3 right;
		static Vector3 forward;
		static Vector3 back;
	};
}