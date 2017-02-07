#include "Force.h"

Force::Force(void)
{
}

Vector2* Force::objectPosition(PhysicsObject* obj)
{
	return &(obj->position);
}

Vector2* Force::objectMomentum(PhysicsObject* obj)
{
	return &(obj->momentum);
}

double* Force::objectMass(PhysicsObject* obj)
{
	return &(obj->mass);
}


Force::~Force(void)
{
}
