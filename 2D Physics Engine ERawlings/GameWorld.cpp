#include "GameWorld.h"


GameWorld::GameWorld(void)
{
	this->isActive = true;
	this->geometry = std::list<Edge2>();
	this->geometry.push_front(Edge2(Vector2(50, 430), Vector2(50, 430) + Vector2(640, Bearing(0.2625))));
	this->geometry.push_front(Edge2(Vector2(590, 430), Vector2(590, 49)));
	this->geometry.push_front(Edge2(Vector2(591, 50), Vector2(50, 50)));
	this->geometry.push_front(Edge2(Vector2(50, 50), Vector2(50, 430)));
	this->geometry.push_front(Edge2(Vector2(25, 305), Vector2(175, 455)));
	this->geometry.push_front(Edge2(Vector2(465, 455), Vector2(615, 305)));
	this->geometry.push_front(Edge2(Vector2(280, 200), Vector2(360, 200)));
	this->geometry.push_front(Edge2(Vector2(360, 200), Vector2(360, 280)));
	this->geometry.push_front(Edge2(Vector2(360, 280), Vector2(280, 280)));
	this->geometry.push_front(Edge2(Vector2(280, 280), Vector2(280, 200)));
	this->entities = std::list<Entity*>();
	this->physicsObjects = std::list<PhysicsObject*>();
	PointObject* pointObject = new PointObject(Vector2(75,75), Vector2(150, -250), 1);
	this->physicsObjects.push_front(pointObject);
	//PlayerTest* player = new PlayerTest();
	//this->entities.push_front(player);
	this->forces = std::list<Force*>();
	LinearDirectionalForce* force = new LinearDirectionalForce(Vector2(0, 300));
	force->addObject(pointObject);
	this->forces.push_front(force);
	//this->player = player;
}

void GameWorld::activate()
{
	this->isActive = true;
}

void GameWorld::deactivate()
{
	this->isActive = false;
}

void GameWorld::update(const double& time)
{
	if (this->isActive == true){
		std::list<Entity*>::iterator iterator;
		for (iterator = this->entities.begin(); iterator != this->entities.end(); ++iterator) {
			(*iterator)->update(geometry);
		}
		std::list<PhysicsObject*>::iterator iterator2;
		for (iterator2 = this->physicsObjects.begin(); iterator2 != this->physicsObjects.end(); ++iterator2) {
			(*iterator2)->update(1./60);
		}
		std::list<Force*>::iterator iterator3;
		for (iterator3 = this->forces.begin(); iterator3 != this->forces.end(); ++iterator3) {
			(*iterator3)->update(1. / 60);
		}
	}
}

void GameWorld::mouseAt(int x, int y)
{

}

void GameWorld::mouseClick(int x, int y)
{

}

RenderData GameWorld::getRenderData() const
{
	RenderData renderData = RenderData();
	if (this->isActive == true){
		std::list<Entity*>::const_iterator iterator;
		for (iterator = this->entities.begin(); iterator != this->entities.end(); ++iterator) {
			renderData.addRenderData((*iterator)->getRenderData());
		}
		std::list<PhysicsObject*>::const_iterator iterator3;
		for (iterator3 = this->physicsObjects.begin(); iterator3 != this->physicsObjects.end(); ++iterator3) {
			Vector2 pos = (*iterator3)->getPosition();
			renderData.addPoint(pos.x, pos.y, 0, 255, 0, 255, 255, 1);
		}
		std::list<Edge2>::const_iterator edgeIterator;
		for (edgeIterator = this->geometry.begin(); edgeIterator != this->geometry.end(); ++edgeIterator) {
			renderData.addLine((edgeIterator)->getU().x, (edgeIterator)->getU().y, 0, (edgeIterator)->getV().x, (edgeIterator)->getV().y, 0, 60, 140, 40, 255, 1);
			Vector2 center = ((edgeIterator)->getU() + (edgeIterator)->getV()) / 2;
			Vector2 angleshow = center + Vector2(10, (edgeIterator)->getBearing() - 0.25);
			renderData.addLine(center.x, center.y, 0, angleshow.x, angleshow.y, 0, 60, 140, 40, 255, 1);
		}
	}
	return renderData;
}

void GameWorld::playerMoveLeft(){
	//this->player->moveLeft();
}

void GameWorld::playerMoveRight(){
	//this->player->moveRight();
}

void GameWorld::playerJump(){
	//this->player->jump();
}

void GameWorld::playerMoveDown(){
	//this->player->moveDown();
}

GameWorld::~GameWorld(void)
{
	//delete &this->isActive;
}
