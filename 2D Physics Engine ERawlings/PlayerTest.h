#pragma once
#include "Entity.h"
#include "Edge2.h"
#include "EdgeIntercept.h"
class PlayerTest : public Entity
{
public:
	PlayerTest();
	void update(const std::list<Edge2> geometry);
	RenderData getRenderData() const;
	void moveLeft();
	void moveRight();
	void jump();
	void moveDown();
	~PlayerTest();
private:
	Vector2 position;
	Vector2 momentum;
	double mass;
	//hit box
	//collision box
	double health;
	double armour;
	//weapons
	//abilities
	//forces
	void runCollisions(std::list<Edge2> geometry, double secondsRemaining, int attempts);
};

