#pragma once
#include "Force.h"
class LinearDirectionalForce :
	public Force
{
public:
	LinearDirectionalForce();
	LinearDirectionalForce(const Vector2& force);
	void update(const double &seconds);
	void addObject(PhysicsObject* obj);
	void removeObject(const PhysicsObject &obj);
	~LinearDirectionalForce();
private:
	Vector2 force;
};

