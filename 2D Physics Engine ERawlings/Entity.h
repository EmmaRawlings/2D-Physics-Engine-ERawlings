#pragma once
#include "RenderData.h"
#include "Edge2.h"
class Entity
{
public:
	Entity(void);
	virtual void update(std::list<Edge2> geometry) = 0;
	virtual RenderData getRenderData() const = 0;
	~Entity(void);
};

