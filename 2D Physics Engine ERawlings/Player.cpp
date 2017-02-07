#include "Player.h"


Player::Player(Vector2 position)
{
	double mass = 1;
	double gravityStrength = 300;
	this->body = PointObject(position, Vector2(), mass);
	this->gravity = LinearDirectionalForce(Vector2(0, gravityStrength*mass));
}

Player::~Player(void)
{
}
