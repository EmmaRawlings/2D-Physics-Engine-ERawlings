#include "stdafx.h"
#include "FireWork.h"


FireWork::FireWork(const Vector2& position, const Bearing& direction)
{
	this->position = position;
	this->momentum = Vector2();
	this->mass = 0.2;
	this->direction = direction;
}

FireWork::FireWork(const Vector2& position, const Vector2& direction)
{
	this->position = position;
	this->momentum = Vector2();
	this->mass = 0.2;
	this->direction = direction.getBearing();
}

void FireWork::update(const double& seconds) {
	this->momentum += Vector2(2., this->direction) * seconds;
}

Vector2 FireWork::getPosition() const
{
	return this->position;
}

Vector2 FireWork::getMomentum() const
{
	return this->momentum;
}

double FireWork::getMass() const
{
	return this->mass;
}

FireWork::~FireWork()
{
}
