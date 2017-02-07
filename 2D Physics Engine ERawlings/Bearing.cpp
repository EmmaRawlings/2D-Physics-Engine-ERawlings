#include "Bearing.h"

double moduloDoubles(const double& d1, const double& d2){
	double result;
	if (d1 < 0){
		result = d1 + d2;
		result = moduloDoubles(result, d2);
	} else {
		if (d1 < d2){
			result = d1;
		}
		else {
			result = d1 - d2;
			result = moduloDoubles(result, d2);
		}
	}
	return result;
}

Bearing::Bearing()
{
	this->value = 0;
}

Bearing::Bearing(const double& ratio)
{
	this->value = moduloDoubles(ratio,1);
}

Bearing::Bearing(const Bearing &bearing)
{
	this->value = bearing.value;
}

void Bearing::setRadians(const double& radians){
	this->value = moduloDoubles(radians/(2*M_PI),1);
}

void Bearing::setDegrees(const double& degrees){
	this->value = moduloDoubles(degrees / 360.0, 1);
}

void Bearing::setRatio(const double& ratio){
	this->value = moduloDoubles(ratio, 1);
}

Bearing operator+(const Bearing &b1, const Bearing &b2)
{
	Bearing result;
	result.value = moduloDoubles(b1.value + b2.value,1);
	return result;
}

Bearing operator-(const Bearing &b1, const Bearing &b2)
{
	Bearing result;
	result.value = moduloDoubles(b1.value - b2.value, 1);
	return result;
}

Bearing operator*(const Bearing &b1, const double& d1)
{
	Bearing result;
	result.value = moduloDoubles(b1.value * d1, 1);
	return result;
}

Bearing operator/(const Bearing &b1, const double& d1)
{
	Bearing result;
	result.value = moduloDoubles(b1.value / d1, 1);
	return result;
}

Bearing& Bearing::operator=(const Bearing &b1)
{
	this->value = moduloDoubles(b1.value, 1);
	return *this;
}

Bearing& Bearing::operator=(const double& d1)
{
	this->value = moduloDoubles(d1, 1);
	return *this;
}

bool withinRange(const Bearing &b1, const Bearing &b2, const double range) {
	double testRatio = b1.ratio();
	double rangeRatio = b2.ratio();
	return ((testRatio > rangeRatio - range && testRatio < rangeRatio + range) || (testRatio > rangeRatio - range - 1 && testRatio < rangeRatio + range - 1) || (testRatio > rangeRatio - range + 1 && testRatio < rangeRatio + range + 1));
}

double Bearing::radians() const
{
	return 2 * M_PI * this->value;
}

double Bearing::degrees() const
{
	return 360 * this->value;
}

double Bearing::ratio() const
{
	return this->value;
}

Bearing::~Bearing()
{
}
