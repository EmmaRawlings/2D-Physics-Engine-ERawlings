#pragma once
#include "Vector2.h"
#include "Edge2.h"
class EdgeIntercept
{
public:
	EdgeIntercept(const Edge2& e1, const Edge2& e2);
	EdgeIntercept(const EdgeIntercept& eInt);
	EdgeIntercept& operator=(const EdgeIntercept& eInt);
	bool doesInterceptExist() const;
	Vector2 getIntercept() const;
	Edge2 getEdge() const;
	~EdgeIntercept(void);
private:
	bool exist;
	Vector2* position;
	Edge2* edge;
	bool withinRangeInclusive(const double& a, const double& u, const double& v);
};

