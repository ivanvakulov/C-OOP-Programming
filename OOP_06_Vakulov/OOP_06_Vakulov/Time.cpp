//Vakulov
//3/4/2017

#include "Time.h"

const double Time::hourToDec = 1./3600.;

Time::Time(int s, int m, int h):
   _seconds(s), 
   _minutes(m), 
   _hours(h)
{
   normalizeTime();
#ifndef NDEBUG
   cout<<"Time created - "<<*this<<endl;
#endif
   return;
}

Time::Time(const Time& t):_seconds(t._seconds), _minutes(t._minutes), _hours(t._hours)
{
#ifndef NDEBUG
   cout<<"Time copied - "<<*this<<", from - "<<t<<endl;
#endif
   return;
}

Time::~Time(){
#ifndef NDEBUG
   cout<<"Time deleted - "<<*this<<endl;
#endif
}

Time& Time::operator=(const Time& t)
{
	if(this != &t){
		   _hours=t._hours;
		   _minutes=t._minutes;
		   _seconds=t._seconds;
	}
   return *this;
}

void Time::normalizeTime()
{
	if(_hours < 0 || _minutes < 0 || _seconds < 0) throw BadTime(_seconds,_minutes,_hours);
	_hours+=((_minutes+(_seconds/60))/60);
	if(_hours >= 24) _hours%=24;
	_minutes=(_minutes+(_seconds/60))%60;
	_seconds%=60;
}

void Time::setHours(int h)
{
   _hours=h;
   normalizeTime();
   return;
}

void Time::setMinutes(int m)
{
   _minutes=m;
   normalizeTime();
   return;
}

void Time::setSeconds(int s)
{
   _seconds=s;
   normalizeTime();
   return;
}

ostream& operator<<(ostream& os, const Time& t)
{
   os<<"("<<t.hours()<<"h:"<<t.minutes()<<"m:"<<t.seconds()<<"s)";
   return os;
}

Time::operator int() const
{
   return _hours*3600+_minutes*60+_seconds;
}

Time::operator double() const{
	return static_cast<int>(*this)*hourToDec;
}

const Time& Time::operator++()
{
	++_seconds;
	if (_seconds > 59){
		_seconds = 0;
		if (++_minutes > 59){
			_minutes = 0;
			if (++_hours > 23){
				_hours = 0;
			}
		}
	}
	return *this;
}

const Time Time::operator++(int i)
{
   const Time res(*this);
   setSeconds(seconds()+1);
   return res;
}

const Time& Time::operator--()
{
	--_seconds;
   if(_seconds < 0){
		_seconds = 59;
		if(--_minutes < 0){
			_minutes = 59;
			if(--_hours < 0){
				_hours = 23;
			}
		}
	}
   return *this;
}

const Time Time::operator--(int i)
{
   const Time res(*this);
   setSeconds(seconds()-1);
   return res;
}

double operator+(const Time& t1, const Time& t2)
{
	return double(t1) + double(t2);
}

ostream& operator<<(ostream& os, const Time::BadTime& t)
{
   os<<"("<<t.hours()<<"h:"<<t.minutes()<<"m:"<<t.seconds()<<"s)";
   return os;
}

void timer(const Date& d, const Time& t, const Time& interval) 
{ 
	struct tm * today = new tm; 
	time_t timer; 
	time( &timer ); 
	today = gmtime(&timer); 
	if(today->tm_mday == d.day() && today->tm_mon + 1 == d.month() && today->tm_year + 1900 == d.year()) { 
		 int end_time = static_cast<int>(t); 
		 int interval_time = static_cast<int>(interval); 
		 int now_time = static_cast<int>(Time(today->tm_sec, today->tm_min, (today->tm_hour) == 22 ? 0 : ((today->tm_hour) + 3))); 
		 int start = 0; 
		 cout<<"Timer started" << t << endl; 
		 while(++now_time < end_time){ 
			 cout<<now_time<<" - "<<end_time<<endl;
			 Sleep(1000);
		 } 
		 cout << "Time ended" << endl; 
		 while ((start++ < interval_time)) { Sleep(1000); } 
		 cout << "Time alert" << endl; 
		 int a = 750; 
 
		 Beep(392, a); 
		 Beep(392, a); 
		 Beep(392, a); 
		 Beep(311, a*0.75); 
		 Beep(466, a*0.25); 
 
		 Beep(392, a); 
		 Beep(311, a*0.75); 
		 Beep(466, a*0.25); 
		 Beep(392, a*2); 
 
		 Beep(587, a); 
		 Beep(587, a); 
		 Beep(587, a); 
		 Beep(622, a*0.75); 
		 Beep(466, a*0.25); 
 
		 Beep(369, a); 
		 Beep(311, a*0.75); 
		 Beep(466, a*0.25); 
		 Beep(392, a*2); 
	} 
	return; 
}