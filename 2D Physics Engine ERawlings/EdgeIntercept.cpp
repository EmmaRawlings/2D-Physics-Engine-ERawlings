#include "EdgeIntercept.h"


EdgeIntercept::EdgeIntercept(const Edge2& e1, const Edge2& e2)
{
	this->edge = new Edge2(e2);

	if (e1.getU().x==e1.getV().x){
		//e1 is vertical
		if (e2.getU().x ==e2.getV().x){
			//e2 is vertical
			this->exist = false;
			this->position = new Vector2(0,0);
		} else {
			//e2 is not vertical
			double m2 = (e2.getV().y - e2.getU().y) / (e2.getV().x - e2.getU().x); //gradient of second line
			double c2 = e2.getU().y - m2*e2.getU().x; //displacement of second line
			double x = e1.getU().x;
			double y = m2*x + c2;
			this->exist = (this->withinRangeInclusive(x, e1.getU().x, e1.getV().x) && this->withinRangeInclusive(y, e1.getU().y, e1.getV().y) && this->withinRangeInclusive(x, e2.getU().x, e2.getV().x) && this->withinRangeInclusive(y, e2.getU().y, e2.getV().y));
			this->position = new Vector2(x, y);
		}
	}
	else {
		//e1 is not vertical
		if (e2.getU().x == e2.getV().x) {
			//e2 is vertical
			double m1 = (e1.getV().y - e1.getU().y) / (e1.getV().x - e1.getU().x); //gradient of second line
			double c1 = e1.getU().y - m1*e1.getU().x; //displacement of second line
			double x = e2.getU().x;
			double y = m1*x + c1;
			this->exist = (this->withinRangeInclusive(x, e1.getU().x, e1.getV().x) && this->withinRangeInclusive(y, e1.getU().y, e1.getV().y) && this->withinRangeInclusive(x, e2.getU().x, e2.getV().x) && this->withinRangeInclusive(y, e2.getU().y, e2.getV().y));
			this->position = new Vector2(x, y);
		}
		else {
			//e2 is not vertical
			double m1 = (e1.getV().y - e1.getU().y) / (e1.getV().x - e1.getU().x); //gradient of first line
			double c1 = e1.getU().y - m1*e1.getU().x; //displacement of first line
			double m2 = (e2.getV().y - e2.getU().y) / (e2.getV().x - e2.getU().x); //gradient of second line
			double c2 = e2.getU().y - m2*e2.getU().x; //displacement of second line
			double x = (c1 - c2) / (m2 - m1);
			double y = m2*x + c2;
			this->exist = (this->withinRangeInclusive(x, e1.getU().x, e1.getV().x) && this->withinRangeInclusive(y, e1.getU().y, e1.getV().y) && this->withinRangeInclusive(x, e2.getU().x, e2.getV().x) && this->withinRangeInclusive(y, e2.getU().y, e2.getV().y));
			this->position = new Vector2(x, y);
		}
	}
}

EdgeIntercept::EdgeIntercept(const EdgeIntercept& eInt)
{
	this->position = new Vector2(*eInt.position);
	this->exist =eInt.exist;
}

EdgeIntercept& EdgeIntercept::operator=(const EdgeIntercept& eInt)
{
	delete this->position;
	this->position = new Vector2(*eInt.position);
	this->exist = eInt.exist;
	return *this;
}

bool EdgeIntercept::withinRangeInclusive(const double& a, const double& u, const double& v)
{
	return ((a >= u && a <= v) || (a <= u && a >= v));// || (a==u) || (a==v) );
}

bool EdgeIntercept::doesInterceptExist() const
{
	return this->exist;
}

Vector2 EdgeIntercept::getIntercept() const
{
	return *this->position;
}

Edge2 EdgeIntercept::getEdge() const
{
	return *this->edge;
}

EdgeIntercept::~EdgeIntercept(void)
{
	delete this->position;
}
