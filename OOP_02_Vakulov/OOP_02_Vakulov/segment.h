//Vakulov Ivan 
//04-02-2017
#include "point.h"
#include <cassert>
class Segment{
private:
	static int _freeID;
	const int _myId;
	Point _a;
	Point _b;
public:
	Segment(const double x1=0, const double y1=0,
	const double x2=1, const double y2=0);
	Segment(const Point &start, const Point &end);
	Segment(const Segment&);
	~Segment();
	Segment& operator=(const Segment&);

	inline const Point& start() const{return _a;}
	inline const Point& end() const{return _b;}
	inline Point &Segment::start(){return _a;}
	inline Point &Segment::end(){return _b;}
	inline const double &Segment::startX() const{return _a.x();}
	inline const double &Segment::startY() const{return _a.y();}
	inline const double &Segment::endX() const{return _b.x();}
	inline const double &Segment::endY() const{return _b.y();}
	inline double &Segment::startX(){return _a.x();}
	inline double &Segment::startY(){return _a.y();}
	inline double &Segment::endX(){return _b.x();}
	inline double &Segment::endY(){return _b.y();}
	double length () const;
	double distance (const Point&) const;
	inline const int getID() const{return _myId;}
};

ostream& operator<<(ostream &, const Segment &);