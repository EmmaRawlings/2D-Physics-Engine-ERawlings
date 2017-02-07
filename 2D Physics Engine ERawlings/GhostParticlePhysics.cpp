#include "GhostParticlePhysics.h"


GhostParticlePhysics::GhostParticlePhysics()
{
	this->position = Vector2();
	this->momentum = Vector2();
	this->mass = 1;
}

GhostParticlePhysics::GhostParticlePhysics(const Vector2 &position, const Vector2 &momentum, const double &mass)
{
	this->position = position;
	this->momentum = momentum;
	this->mass = mass;
}

void GhostParticlePhysics::update(const double &seconds){
	//force affecting momentum
	this->position += (this->momentum * seconds) / this->mass;
}

GhostParticlePhysics::~GhostParticlePhysics()
{
}
