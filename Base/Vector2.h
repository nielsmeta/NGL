#pragma once
namespace NGL
{
	class Vector2
	{
		public:
			
			int GetX();
			int GetY();

			void SetX(int _x);
			void SetY(int _y);
			void Info();

			static Vector2 Zero()
			{
				return zero;
			}

			static Vector2 One()
			{
				return one;
			}

			static Vector2 Up()
			{
				return up;
			}

			static Vector2 Down()
			{
				return down;
			}

			Vector2 operator + (Vector2  other)
			{
				return Vector2(x + other.x, y + other.y);
			}
			Vector2 operator - (Vector2 other)
			{
				return Vector2(x - other.x, y - other.y);
			}

			void operator = (Vector2 other)
			{
				x = other.x;
				y = other.y;
			}

			bool operator == (Vector2 other)
			{
				return x == other.x && y == other.y;
			}

			bool operator != (Vector2 other)
			{
				return !(*this == other);
			}

			void operator += (Vector2 other)
			{
				*this = (*this + other);
			}

			void operator -= (Vector2 other)
			{
				*this = (*this - other);
			}

			Vector2(int _x, int _y)
			{
				x = _x;
				y = _y;
			}

			Vector2()
			{
				x = y = 0;
			}

		private:
			int x, y;
			static Vector2 zero;
			static Vector2 one;
			static Vector2 up;
			static Vector2 down;
			static Vector2 left;
			static Vector2 right;
	};
}