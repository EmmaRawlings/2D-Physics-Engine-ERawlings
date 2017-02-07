#pragma once
#include "Vector2.h"
#include "PhysicsObject.h"

class PointObject :
	public PhysicsObject
{
public:
	PointObject();
	PointObject(const Vector2& position);
	PointObject(const Vector2& position, const Vector2& momentum);
	PointObject(const Vector2& position, const Vector2& momentum, const double& mass);
	PointObject(const PointObject& pObject);
	PointObject& operator=(const PointObject& pObject);
	Vector2 getPosition() const;
	Vector2 getMomentum() const;
	Vector2 getVelocity() const;
	double getMass() const;
	void update(const double& seconds);
	~PointObject(void);
};

