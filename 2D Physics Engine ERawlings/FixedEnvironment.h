#pragma once
#include <list>
#include "Edge2.h"
class FixedEnvironment
{
public:
	FixedEnvironment(const std::list<Edge2>& geo);
	~FixedEnvironment(void);
private:
	std::list<Edge2> geo;
};

