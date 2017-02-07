#include "PointObject.h"

PointObject::PointObject()
{
	this->position = Vector2();
	this->momentum = Vector2();
	this->mass = 1;
}

PointObject::PointObject(const Vector2 &position)
{
	this->position = position;
	this->momentum = Vector2();
	this->mass = 1;
}

PointObject::PointObject(const Vector2& position, const Vector2& momentum)
{
	this->position = position;
	this->momentum = momentum;
	this->mass = 1;
}

PointObject::PointObject(const Vector2& position, const Vector2& momentum, const double& mass)
{
	this->position = position;
	this->momentum = momentum;
	this->mass = mass;
}

PointObject::PointObject(const PointObject& pObject) {
	this->position = pObject.position;
	this->momentum = pObject.momentum;
	this->mass = pObject.mass;
}

PointObject& PointObject::operator=(const PointObject& pObject) {
	this->position = pObject.position;
	this->momentum = pObject.momentum;
	this->mass = pObject.mass;
	return *this;
}

void PointObject::update(const double& seconds)
{
	this->position += (this->momentum * seconds) / this->mass;
}

Vector2 PointObject::getMomentum() const
{
	return this->momentum;
}

Vector2 PointObject::getVelocity() const
{
	return this->momentum/this->mass;
}

Vector2 PointObject::getPosition() const
{
	return this->position;
}

double PointObject::getMass() const
{
	return this->mass;
}

PointObject::~PointObject(void)
{
}
