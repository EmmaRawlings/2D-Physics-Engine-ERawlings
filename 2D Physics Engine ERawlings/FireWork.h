#pragma once
#include "PhysicsObject.h"
class FireWork :
	public PhysicsObject
{
public:
	FireWork(const Vector2& position, const Bearing& direction);
	FireWork(const Vector2& position, const Vector2& direction);
	void update(const double& seconds);
	Vector2 getPosition() const;
	Vector2 getMomentum() const;
	double getMass() const;
	~FireWork();
private:
	Bearing direction;
};

