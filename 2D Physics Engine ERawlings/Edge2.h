#pragma once
#include "Vector2.h"
class Edge2
{
public:
	Edge2();
	Edge2(const Vector2& u, const Vector2& v);
	Edge2(const Edge2& e2);
	Edge2& operator=(const Edge2& e2);
	friend bool operator==(const Edge2& lhs, const Edge2& rhs);
	Vector2 getU() const;
	Vector2 getV() const;
	Bearing getBearing() const;
	~Edge2(void);
private:
	Vector2* u;
	Vector2* v;
};