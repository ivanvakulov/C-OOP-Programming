//Vakulov Ivan 
//04-02-2017
#include <iostream>
using namespace std;

#ifndef _POINT_H_

#define _POINT_H_

class Point
{
private:
	static int freeID;
	const int pointID;
	double _x;
	double _y;
public:
	Point (double x=0, double y=0);
	Point (const Point &);
	~Point();
	Point& operator=(const Point &);
	inline double& x(){return _x;}
	inline double& y(){return _y;}
	inline const double& x()const{return _x;}
	inline const double& y()const{return _y;}
	inline const int getID() const{return pointID;}
	inline static int amount(){return freeID;}
};

ostream& operator<<(ostream&, const Point&);
const Point operator+ (const Point & u, const Point & v);
Point& operator+=(Point &, const Point&);
bool operator==(const Point & u, const Point &v);
bool operator!=(const Point & u, const Point &v);

#endif