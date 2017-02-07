#pragma once
#include "Vector2.h"
class PhysicsObject
{
	friend class Force;
	//friend class LinearDirectionalForce;
public:
	PhysicsObject();
	virtual void update(const double& seconds) = 0;
	virtual Vector2 getPosition() const = 0;
	virtual Vector2 getMomentum() const = 0;
	virtual double getMass() const = 0;
	~PhysicsObject();
protected:
	Vector2 position; 
	Vector2 momentum;
	double mass;
};

