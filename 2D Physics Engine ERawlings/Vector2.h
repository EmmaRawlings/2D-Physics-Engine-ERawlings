#include "stdafx.h"
#pragma once
#include "Bearing.h"
class Vector2
{
public:
	Vector2(); //default constructor; x = 0, y = 0
	Vector2(const double& x, const double& y); //constructs via coordinates
	Vector2(const double& length, const Bearing& bearing);
	double getLength() const; //returns length
	Bearing getBearing() const; //returns bearing (untested)
	//Vector2 getComponentVector(double angle, double angle2) const;

	Vector2 add(const Vector2& add) const; //returns this + input
	Vector2 sub(const Vector2& sub) const; //returns this - input
	Vector2 scalarMultiply(const double& scalar) const; //returns this*input

	Vector2 operator+(const Vector2& add) const;
	Vector2 operator-(const Vector2& sub) const;
	Vector2 operator*(const double& scalar) const;
	Vector2 operator/(const double& scalar) const;
	Vector2& operator=(const Vector2& rhs);
	Vector2& operator+=(const Vector2& rhs);
	friend bool operator==(const Vector2& lhs, const Vector2& rhs);

	Vector2 atLength(const double& length) const; //returns vector with this vector's bearing at input length
	Vector2 atBearing(const Bearing& bearing) const; //returns vector with this vector's length at input bearing
	~Vector2(void); //deconstructor
	double x;
	double y;
};


