#include "EdgeInterceptData.h"


EdgeInterceptData::EdgeInterceptData(const bool& interceptExists, const Vector2& intercept)
{
	this->interceptExists = interceptExists;
	this->intercept = new Vector2(intercept);
}

EdgeInterceptData::EdgeInterceptData(const EdgeInterceptData& eIntData)
{
	this->intercept = new Vector2(*eIntData.intercept);
	this->interceptExists = eIntData.interceptExists;
}

EdgeInterceptData& EdgeInterceptData::operator=(const EdgeInterceptData& eIntData)
{
	delete this->intercept;
	this->intercept = new Vector2(*eIntData.intercept);
	this->interceptExists = eIntData.interceptExists;
	return *this;
}

bool EdgeInterceptData::doesInterceptExist() const
{
	return this->interceptExists;
}

Vector2 EdgeInterceptData::getIntercept() const
{
	return *this->intercept;
}

EdgeInterceptData::~EdgeInterceptData(void)
{
	delete this->intercept;
}
