#include "Edge2.h"
#include <math.h>

Edge2::Edge2()
{
	this->u = new Vector2();
	this->v = new Vector2();
}

Edge2::Edge2(const Vector2& u, const Vector2& v)
{
	this->u= new Vector2(u);
	this->v= new Vector2(v);
}

Edge2::Edge2(const Edge2& e2)
{
	this->u = new Vector2(*e2.u);
	this->v = new Vector2(*e2.v);
}

Edge2& Edge2::operator=(const Edge2& e2)
{
	delete this->u;
	delete this->v;
	this->u = new Vector2(*e2.u);
	this->v = new Vector2(*e2.v);
	return *this;
}

bool operator==(const Edge2& lhs, const Edge2& rhs)
{
	return (lhs.u == rhs.u && lhs.v == rhs.v);
}

Vector2 Edge2::getU() const
{
	return *this->u;
}

Vector2 Edge2::getV() const
{
	return *this->v;
}

Bearing Edge2::getBearing() const
{
	//tan(q) = o/a
	//q = atan(o/a)
	//q = atan(x/y)
	Bearing result;
	result.setRadians(atan2((this->v->y) - (this->u->y), (this->v->x) - (this->u->x)));
	return result;
}

Edge2::~Edge2(void)
{
	delete this->u;
	delete this->v;
}
