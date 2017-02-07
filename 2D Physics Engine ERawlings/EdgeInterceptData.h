#pragma once
#include "Vector2.h"
class EdgeInterceptData
{
public:
	EdgeInterceptData(const bool& interceptExists, const Vector2& intercept);
	EdgeInterceptData(const EdgeInterceptData& eIntData);
	EdgeInterceptData& operator=(const EdgeInterceptData& eIntData);
	bool doesInterceptExist() const;
	Vector2 getIntercept() const;
	~EdgeInterceptData(void);
private:
	bool interceptExists;
	Vector2* intercept;
};

