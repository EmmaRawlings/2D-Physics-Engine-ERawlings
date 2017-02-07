#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
class Bearing
{
public:
	Bearing(); //Default constructor; value = 0
	Bearing(const double& ratio); //Constructor; this.value = ratio
	Bearing(const Bearing &bearing); //Copy Constructor; this.value = bearing.value
	void setRadians(const double& radians);
	void setDegrees(const double& degrees);
	void setRatio(const double& ratio);
	friend Bearing operator+(const Bearing& b1, const Bearing& b2); //Returns the result of adding two Bearings
	friend Bearing operator-(const Bearing& b1, const Bearing& b2); //Returns the result of performing subtraction on two Bearings
	friend Bearing operator*(const Bearing& b1, const double& d1); //Returns the result of multiplying a Bearing by a scalar
	friend Bearing operator/(const Bearing& b1, const double& d1); //Returns the result of dividing a Bearing by a scalar
	Bearing& operator=(const Bearing& b1); //Sets this Bearing to be equal to another Bearing
	Bearing& operator=(const double& d1); //Sets the value of this Bearing to be equal to the input value
	friend bool withinRange(const Bearing &b1, const Bearing &b2, const double range);
	double radians() const; //Returns the angle of the Bearing in radians; full circle = 2*Pi
	double degrees() const; //Returns the angle of the Bearing in degrees; full circle = 360
	double ratio() const; //Returns the angle of the Bearing as a ratio; full circle = 1
	~Bearing(); //Destructor
private:
	double value; // the angle, as a ratio of a full circle, of this bearing (half a circle, quarter circle, etc), value>=0, value<1
	friend double moduloDoubles(const double& d1, const double& d2);
};

