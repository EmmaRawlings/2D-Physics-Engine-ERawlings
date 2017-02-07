#pragma once
#include "PointObject.h"
#include <list>
class Force
{
public:
	Force(void);
	virtual void update(const double& seconds) = 0;
	virtual void addObject(PhysicsObject* obj) = 0;
	virtual void removeObject(const PhysicsObject& obj) = 0;
	~Force(void);
protected:
	std::list<PhysicsObject*> objects;
	Vector2* objectPosition(PhysicsObject* obj);
	Vector2* objectMomentum(PhysicsObject* obj);
	double* objectMass(PhysicsObject* obj);
};

