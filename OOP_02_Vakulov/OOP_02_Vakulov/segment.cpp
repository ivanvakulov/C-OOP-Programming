//Vakulov Ivan 
//04-02-2017
#include "segment.h"

int Segment::_freeID = 0;

Segment::Segment(const double x1, const double y1,
	const double x2, const double y2) : _myId(++_freeID), _a(x1,y1), _b(x2,y2){
#ifndef NDEBUG
	cout << "Created segment(coordinates) with ID:" << _myId << " - " << *this<< endl;
#endif
}

Segment::Segment(const Point &start, const Point &end): _myId(++_freeID), _a(start), _b(end){
#ifndef NDEBUG
	cout << "Created segment(points) with ID:" << _myId << " - " <<*this<< endl;
#endif
}

Segment::Segment(const Segment& seg): _myId(++_freeID), _a(seg._a), _b(seg._b){
#ifndef NDEBUG
	cout << "Copied segment with ID:"<< seg._myId << " to a new segment with ID:" << _myId << " - " <<*this<< endl;
#endif
}

Segment::~Segment(){
#ifndef NDEBUG
	cout << "Deleted segment with ID:" << _myId << " - " <<*this<< endl;
#endif
}

Segment& Segment::operator=(const Segment& seg){
	if(this != &seg){
		_a = seg._a;
		_b = seg._b;
	}
	return *this;
}

double Segment::length() const
{
   return sqrt((_a.x()-_b.x())*(_a.x()-_b.x())
      +(_a.y()-_b.y())*(_a.y()-_b.y()));
}

double Segment::distance(const Point& p) const { 
	double A = (_a.y() - _b.y()); 
	double B = (_b.x() - _a.x()); 
	double C = _a.x()*_b.y() -_b.x() * _a.y(); 
	assert((A!=0)||(B!=0));
	if (A == 0) 
		return fabs((B * p.y() + C) / B); 
	else if (B == 0) 
		return fabs((A * p.y() + C) / A); 
	return fabs((A * p.x() + B * p.y() + C) / sqrt(A * A + B * B)); 
}

ostream& operator<<(ostream& ostream, const Segment& seg){
	ostream << "{" << seg.start() << " " << seg.end()<<" }";
	return ostream;
}