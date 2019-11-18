#include "Vector.h"

/**
* The Vec2 class is a simple representation of a two dimensional coordinate.
* Overloading of arithmetic operators allows users to more easily manipulate
* the Vec2 class.
*
* @author Casey Singleton
* @version 1.0
*/

/**
* Default constructor for Vec2 class
* Public members x and y are set to 0.0 by default
*/
Vec2::Vec2(void) :
	x(0.0f),
	y(0.0f) {}

/**
* Overloaded constructor for Vec2 class
* @param px : The desired value for the horizontal x coordinate
* @param py : The desired value for the vertical y coordinate
*/
Vec2::Vec2(float px, float py)
{
  x = px;
  y = py;
}

Vec2::~Vec2(void) {}

/**
* Sets the left hand side vector equal to the values of the right hand side vector
* @param rhs : The right hand side vector whos values are to be copied
*/
Vec2& Vec2::operator=(const Vec2& rhs)
{
	if (this != &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}
	return (*this);
}

/**
* Adds the values of two vectors
* @param v : The vector whos values are to be added
*
* @return : A new vector of Vec2 class that is the sum of the values of two other vectors
*/
Vec2 Vec2::operator+(const Vec2& v)
{
	return (Vec2(x + v.x, y + v.y));
}

/**
* Subtracts the values of two vectors
* @param v : The vector whos values are to be subtracted
*
* @return : A new vector of Vec2 class that is the difference of the values of two other vectors
*/
Vec2 Vec2::operator-(const Vec2& v)
{
	return (Vec2(x - v.x, y - v.y));
}

/**
* Multiplies the values of two vectors
* @param v : The vector whos values are to be multiplied
*
* @return : A new vector of Vec2 class that is the product of the values of two other vectors
*/
Vec2 Vec2::operator*(const Vec2& v)
{
	return (Vec2(x * v.x, y * v.y));
}

/**
* Divides the values of two vectors
* @param v : The vector whos values are to be divided
*
* @return : A new vector of Vec2 class that is the division of the values of two other vectors
*/
Vec2 Vec2::operator/(const Vec2& v)
{
	return (Vec2(x / v.x, y / v.y));
}

/**
* Addds the left hand side vector to the right hand side vector. Sets the left
* hand side vector to the sum of the two vectors
* @param rhs : The vector to the right of the += operator
*/
Vec2& Vec2::operator+=(const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return (*this);
}

/**
* Subtracts the left hand side vector to the right hand side vector. Sets the left
* hand side vector to the difference of the two vectors
* @param rhs : The vector to the right of the -= operator
*/
Vec2& Vec2::operator-=(const Vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return (*this);
}

/**
* Multiplies the left hand side vector to the right hand side vector. Sets the left
* hand side vector to the product of the two vectors
* @param rhs : The vector to the right of the *= operator
*/
Vec2& Vec2::operator*=(const Vec2& rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return (*this);
}

/**
* Divides the left hand side vector to the right hand side vector. Sets the left
* hand side vector to the division of the two vectors
* @param rhs : The vector to the right of the /= operator
*/
Vec2& Vec2::operator/=(const Vec2& rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	return (*this);
}

/**
* Calculates the distance between two vectors
* @param p1 : The first point or vector
* @param p2 : The second point or vector
*
* @return : A float that is the distance between the two points
*/
float distanceBetweenVectors(const Vec2 &p1, const Vec2 &p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}
