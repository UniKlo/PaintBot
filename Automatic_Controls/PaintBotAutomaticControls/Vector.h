#include <arduino.h>

#ifndef VECTOR_H
# define VECTOR_H

class Vec2
{
	public:
		float x, y;

	public:
		Vec2(void);
		Vec2(float, float);
		~Vec2(void);
		Vec2& operator=(const Vec2&);
		Vec2 operator+(const Vec2&);
		Vec2 operator-(const Vec2&);
		Vec2 operator*(const Vec2&);
		Vec2 operator/(const Vec2&);
		Vec2& operator+=(const Vec2&);
		Vec2& operator-=(const Vec2&);
		Vec2& operator*=(const Vec2&);
		Vec2& operator/=(const Vec2&);
};

float distanceBetweenVectors(const Vec2 &, const Vec2 &);

#endif
