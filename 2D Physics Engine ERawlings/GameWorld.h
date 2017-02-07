#pragma once
#include "RenderData.h"
#include "Entity.h"
#include "Edge2.h"
#include "PlayerTest.h"
#include "PhysicsObject.h"
#include "PointObject.h"
#include "LinearDirectionalForce.h"
class GameWorld
{
public:
	GameWorld();
	void activate();
	void deactivate();
	void update(const double& time);
	void mouseAt(int x, int y); //update cursor position
	void mouseClick(int x, int y); //click the button where the cursor is
	RenderData getRenderData() const;
	void playerMoveLeft();
	void playerMoveRight();
	void playerJump();
	void playerMoveDown();
	~GameWorld();
private:
	bool isActive;
	std::list<Edge2> geometry;
	std::list<Entity*> entities;
	std::list<PhysicsObject*> physicsObjects;
	std::list<Force*> forces;
	//PlayerTest* player;
};

