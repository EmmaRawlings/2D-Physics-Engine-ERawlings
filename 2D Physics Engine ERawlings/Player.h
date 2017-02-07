#pragma once
#include "Entity.h"
#include "Vector2.h"
#include "PointObject.h"
#include "LinearDirectionalForce.h"
class Player
{
public:
	Player(Vector2 position);
	void update(const std::list<Edge2> geometry);
	RenderData getRenderData() const;
	void moveLeft();
	void moveRight();
	void jump();
	void moveDown();
	~Player();
private:
	LinearDirectionalForce gravity;
	//collision force
	//motion force
	//friction force
	//air resistance force
	PointObject body;
};



