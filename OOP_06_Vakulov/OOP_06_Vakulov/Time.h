//Vakulov
//3/4/2017
#include <iostream>
#include "Date.h"
#include <windows.h>
using namespace std;
class Time
{
	private:
		int _hours;
		int _minutes;
		int _seconds;
		void normalizeTime();
	public:
		struct BadTime;
		static const double hourToDec;
		Time (int s=0,int m=0,int h=0);
		Time (const Time&);
		~Time();
		Time& operator=(const Time&);
		operator int() const;
		operator double() const;
		inline const int& hours() const {return _hours;}
		inline const int& minutes() const {return _minutes;}
		inline const int& seconds() const {return _seconds;}
		void setHours(int);
		void setMinutes(int);
		void setSeconds(int);
		const Time& operator++();
		const Time operator++(int);
		const Time& operator--();
		const Time operator--(int);
};
double operator+(const Time&, const Time&);
ostream& operator<<(ostream&, const Time &);

void timer(const Date& d, const Time& t, const Time& interval);

struct Time::BadTime
{
	int _hours;
	int _minutes;
	int _seconds;
	inline const int& hours() const {return _hours;}
	inline const int& minutes() const {return _minutes;}
	inline const int& seconds() const {return _seconds;}
	BadTime(int h,int m,int s):_hours(h), _minutes(m), _seconds(s){};
};
ostream& operator<<(ostream& os, const Time::BadTime & bd);