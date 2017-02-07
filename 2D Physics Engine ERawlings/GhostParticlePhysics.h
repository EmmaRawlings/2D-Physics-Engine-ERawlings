#pragma once
#include "PointObject.h"
class GhostParticlePhysics :
	public PointObject
{
public:
	GhostParticlePhysics();
	GhostParticlePhysics(const Vector2 &position, const Vector2 &momentum, const double &mass);
	void update(const double &seconds);
	~GhostParticlePhysics();
};

