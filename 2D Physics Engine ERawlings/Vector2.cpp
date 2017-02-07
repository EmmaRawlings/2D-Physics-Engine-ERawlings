#include "Vector2.h"
#include <math.h>


Vector2::Vector2() //Creates a Vector with default coordinates (0, 0)
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(const double& x, const double& y) //Creates a Vector with input coordinates
{
	this->x = x;
	this->y = y;
}


Vector2::Vector2(const double& length, const Bearing& bearing)
{
	double angle = bearing.radians();
	this->x = length * sin(angle);
	this->y = length * cos(angle);
}

double Vector2::getLength() const
{
	return pow(pow(x, 2) + pow(y, 2), 0.5);
}

Bearing Vector2::getBearing() const
{
	Bearing result;
	result.setRadians(atan2(y, x));
	return result;
}

Vector2 Vector2::add(const Vector2& add) const
{
	return Vector2(this->x+add.x, this->y+add.y);
}

Vector2 Vector2::operator+(const Vector2& add) const
{
	return this->add(add);
}

Vector2 Vector2::sub(const Vector2& sub) const
{
	return Vector2(this->x-sub.x, this->y-sub.y);
}

Vector2 Vector2::operator-(const Vector2& sub) const
{
	return this->sub(sub);
}

Vector2 Vector2::scalarMultiply(const double& scalar) const
{
	return Vector2(this->x*scalar, this->y*scalar);
}

Vector2 Vector2::operator*(const double& scalar) const
{
	return this->scalarMultiply(scalar);
}

Vector2 Vector2::operator/(const double& scalar) const
{
	return Vector2(this->x/scalar, this->y/scalar);
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	this->x+=rhs.x;
	this->y+=rhs.y;
    return *this;
}

bool operator==(const Vector2& lhs, const Vector2& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

Vector2 Vector2::atLength(const double& length) const
{
	return this->scalarMultiply(length / this->getLength());
}

Vector2 Vector2::atBearing(const Bearing& bearing) const
{
	//U*sin(t) = o
	//U*cos(t) = a
	double angle = bearing.radians();
	return Vector2(this->getLength() * sin(angle), this->getLength() * cos(angle));
}

Vector2::~Vector2(void)
{
}
