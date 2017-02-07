#include "PlayerTest.h"


PlayerTest::PlayerTest()
{
	this->position = Vector2(300, 100);
	this->momentum = Vector2(0, 0);
	this->mass = 1.7;
	this->health = 0;
}

void PlayerTest::runCollisions(std::list<Edge2> geometry, double secondsRemaining, int attempts)
{
	//horizontals are still strange
	//corners allow passthrough

	EdgeIntercept closestIntercept = EdgeIntercept(Edge2(Vector2(0, 0), Vector2(0, 1)), Edge2(Vector2(1, 1), Vector2(1, 2)));
	Vector2 goingto = this->position + ((this->momentum*secondsRemaining) / this->mass);
	Edge2 motion = Edge2(this->position, goingto);
	//check all edges for closest edge that intercepts motion
	for (Edge2 edge : geometry){
		EdgeIntercept intercept = EdgeIntercept(motion, edge);
		if (intercept.doesInterceptExist()){
			Vector2 newDifference = intercept.getIntercept() - this->position;
			Vector2 oldDifference = closestIntercept.getIntercept() - this->position;
			//if the bearing of the motion is not within 90 degrees of the resistant force
			if (newDifference.getLength() < oldDifference.getLength() && withinRange(motion.getBearing(), intercept.getEdge().getBearing()-0.25, 0.25)) {
				closestIntercept = intercept;
			}
		}
	}
	if (closestIntercept.doesInterceptExist() && attempts < 500){
		std::list<Edge2> newGeometry = geometry;
		Bearing resistanceAngle = closestIntercept.getEdge().getBearing() - 0.25;
		double travelSeconds = (((closestIntercept.getIntercept() - this->position).getLength()-0.0001) / (this->momentum / this->mass).getLength());
		if (travelSeconds > secondsRemaining){
			travelSeconds = secondsRemaining;
		}
		this->position += (this->momentum * travelSeconds) / this->mass;
		this->momentum = this->momentum + Vector2(0.0001 + 2 * this->momentum.getLength()*abs(cos(((resistanceAngle - Bearing(0.5)) - this->momentum.getBearing()).radians())), resistanceAngle);
		double newSecondsRemaining = secondsRemaining - travelSeconds;
		this->runCollisions(geometry, newSecondsRemaining, attempts+1);
	}
	else {
		this->position += (this->momentum * secondsRemaining) / this->mass; //this causes it
	}
}

void PlayerTest::update(std::list<Edge2> geometry)
{
	//position u
	//velocity u/s
	//momentum u*m/s
	//force u*m/s^2
	double secondsRemaining = 1. / 60.0;
	double gravityStrength = 1000;
	//this->momentum.y += (gravityStrength * this->mass) * secondsRemaining;
	this->momentum += Vector2((gravityStrength * this->mass) * secondsRemaining, Bearing(0));
	this->runCollisions(geometry, secondsRemaining, 0);
}

RenderData PlayerTest::getRenderData() const
{
	RenderData renderData;
	renderData.addPoint(this->position.x, this->position.y, 0, 255, 255, 255, 255, 1);
	renderData.addLine(this->position.x - 3, this->position.y - 3, 0, this->position.x - 7, this->position.y - 7, 0, 128, 128, 128, 255, 1);
	renderData.addLine(this->position.x - 3, this->position.y + 3, 0, this->position.x - 7, this->position.y + 7, 0, 128, 128, 128, 255, 1);
	renderData.addLine(this->position.x + 3, this->position.y - 3, 0, this->position.x + 7, this->position.y - 7, 0, 128, 128, 128, 255, 1);
	renderData.addLine(this->position.x + 3, this->position.y + 3, 0, this->position.x + 7, this->position.y + 7, 0, 128, 128, 128, 255, 1);

	/*Vector2 angleshow = this->position + Vector2(this->momentum.getLength()/10, this->momentum.getBearing());
	renderData.addLine(this->position.x, this->position.y, 0, angleshow.x, angleshow.y, 0, 255, 0, 0, 255, 1);*/

	return renderData;
}

void PlayerTest::moveLeft(){
	this->momentum.x = -480;
}

void PlayerTest::moveRight(){
	this->momentum.x = 480;
}

void PlayerTest::jump(){
	this->momentum.y = -1000;
}

void PlayerTest::moveDown(){
	this->momentum.x = 0;
}

PlayerTest::~PlayerTest()
{
}
