#include "LinearDirectionalForce.h"

LinearDirectionalForce::LinearDirectionalForce()
{
	this->objects = std::list<PhysicsObject*>();
	this->force = Vector2();
}

LinearDirectionalForce::LinearDirectionalForce(const Vector2 &force)
{
	this->objects = std::list<PhysicsObject*>();
	this->force = force;
}

void LinearDirectionalForce::update(const double &seconds){
	/*PointObject obj = PointObject();
	objectPosition(obj);*/
	std::list<PhysicsObject*>::iterator iterator;
	for (iterator = this->objects.begin(); iterator != this->objects.end(); ++iterator) {
		*objectMomentum(*iterator) += this->force * seconds;
	}
}

void LinearDirectionalForce::addObject(PhysicsObject* obj){
	this->objects.push_front(obj);
}

void LinearDirectionalForce::removeObject(const PhysicsObject &obj){
	//TO BE IMPLEMENTED
}

LinearDirectionalForce::~LinearDirectionalForce()
{
}
