#include "CharacterMotionForce.h"


CharacterMotionForce::CharacterMotionForce()
{
	this->objects = std::list<PhysicsObject*>();
	this->runMomentum = 0;
	this->jumpMomentum = 0;
	this->left = false;
	this->right = false;
	this->jump = false;
}

CharacterMotionForce::CharacterMotionForce(const double &runMomentum, const double &jumpMomentum)
{
	this->objects = std::list<PhysicsObject*>();
	this->runMomentum = runMomentum;
	this->jumpMomentum = jumpMomentum;
	this->left = false;
	this->right = false;
	this->jump = false;
}

void CharacterMotionForce::update(const double &seconds)
{
	//TO BE IMPLEMENTED
}

void CharacterMotionForce::addObject(PhysicsObject* obj)
{
	//TO BE IMPLEMENTED
}

void CharacterMotionForce::removeObject(const PhysicsObject &obj)
{
	//TO BE IMPLEMENTED
}

CharacterMotionForce::~CharacterMotionForce()
{
}
