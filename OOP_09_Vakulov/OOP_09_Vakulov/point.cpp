//Vakulov Ivan 
//04-02-2017
#include "point.h"

int Point::freeID = 0;

Point::Point(double x, double y) : pointID(++freeID), _x(x), _y(y){
#ifndef NDEBUG
	cout << "Created point with ID:" << pointID <<*this<< endl;
#endif
}
Point::~Point(){
#ifndef NDEBUG
	cout << "Deleted point with ID:" << pointID <<*this<< endl;
#endif
}
Point::Point(const Point& u) : pointID(++freeID),_x(u._x),_y(u._y){
#ifndef NDEBUG
	cout << "Copied point with ID:"<< u.pointID <<" to a new point with ID:" << pointID <<*this<< endl;
#endif
}
Point& Point::operator=(const Point &u){
	if(this != &u){
		_x = u._x;
		_y = u._y;
	}
	return *this;
}
bool operator==(const Point& u, const Point& v){
	return u.y() == v.y() && u.x() == v.x();
}
bool operator!=(const Point& u, const Point& v){
	return !(u == v);
}
Point& operator+=(Point& u, const Point& v){
	u.x() += v.x();
	u.y() += v.y();
	return u;
}
const Point operator+(const Point& u, const Point& v){
	return Point(u.x() + v.x(), u.y() + v.y());
}
ostream& operator<<(ostream& ostream, const Point& u){
	ostream << " (" << u.x() << " ; " << u.y() << ")";
	return ostream;
}
