#pragma once
#include "Force.h"
class CharacterMotionForce :
	public Force
{
public:
	CharacterMotionForce();
	CharacterMotionForce(const double &runMomentum, const double &jumpMomentum);
	void update(const double &seconds);
	void addObject(PhysicsObject* obj);
	void removeObject(const PhysicsObject &obj);
	~CharacterMotionForce();
	bool left;
	bool right;
	bool jump;
private:
	double runMomentum;
	double jumpMomentum;
};

