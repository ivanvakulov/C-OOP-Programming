//Vakulov
//Date date(25,2,2017);
#include "Date.h"

bool Date::defaultSet = false;
string Date::monthNames [12]=
{
   "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
   "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
Date Date::defaultDate;


Date::Date(unsigned int d, Month m, unsigned int y)
{
   fillDate(d, m, y);
}

Date::Date(unsigned int d, unsigned int m, unsigned int y)
{
   fillDate(d, Month(m), y);
}

Date::Date (const Date& d) : _day(d._day),_month(d._month),_year(d._year){
#ifndef NDEBUG
	cout<<"Date copied from "<<d<<" - "<<*this<<endl;
#endif
}

Date::~Date(){
#ifndef NDEBUG
	cout<<"Date - "<<*this<<" deleted."<<endl;
#endif
}

bool Date::leapYear(int y)
{
	return  (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int Date::amountOfDays(){
	unsigned int numberOfDays = 0;
	switch(_month)
	{
	case feb:
		numberOfDays=28+leapYear(_year);
		break;
	case apr: case jun: case sep: case nov:
		numberOfDays=30;
		break;
	case jan: case mar: case may:
	case jul: case aug: case oct: case dec:
		numberOfDays = 31;
		break;
	default:
		throw BadDate(_day, _month, _year);
	}
	return numberOfDays;
}

void Date::setDay(unsigned int d){
	if(amountOfDays() < d)throw BadDate(d,_month,_year);
	_day = d;	
}

void Date::setMonth(unsigned int m){
	if(m > 12 || m < 1)throw BadDate(_day,m,_year);
	_month = m;	
}

void Date::setYear(unsigned int y){
	unsigned int temp = _year;
	_year = y;
	if(amountOfDays() < _day){
		_year = temp;
		throw BadDate(_day,_month,y);
	}
}

const Date& Date::operator++() { 
	if(_day == amountOfDays()) { 
		_day = 1; 
		if (_month == 12) { 
			_month = 1; 
			++_year; 
		} else { 
			++_month; 
		} 
	} else { 
		++_day; 
	} 
	return *this; 
} 

const Date Date::operator++(int n){
	Date x(*this);
	++*this; 
	return x;
}

const Date Date::operator--(int n){
	Date x(*this);
	--*this; 
	return x;
}

const Date& Date::operator--() { 
	if (_day == 1) { 
		if (_month == 1) { 
			_month = 12; 
			--_year; 
		} else { 
			--_month; 
		}
		_day = amountOfDays(); 
	} else { 
		--_day; 
	} 
	return *this; 
}

void Date::fillDate(unsigned int d, Month m, unsigned int y) 
{
   if(!defaultSet)
   {
      defaultSet=true;
      setDefault();
#ifndef NDEBUG
      cout<<"Date constructor defaultDate: "<<*this<<endl;
#endif
      return;
   }
   _day=d? d :defaultDate._day;
   _month=m? m :defaultDate._month;
   _year=y? y: defaultDate._year;

   unsigned int numberOfDays = 0;
   switch(_month)
   {
   case feb:
      numberOfDays=28+leapYear(y);
      break;
   case apr: case jun: case sep: case nov:
      numberOfDays=30;
      break;
   case jan: case mar: case may:
   case jul: case aug: case oct: case dec:
      numberOfDays=31;
      break;
   default:
      throw BadDate(_day, _month, _year);
   }
   if((_day<1)||(numberOfDays<_day)||(_year<0))
      throw BadDate(_day, _month, _year);
#ifndef NDEBUG
   cout<<"Date constructor: "<<*this<<endl;
#endif
};

void Date::showDefault()
{
   cout<<defaultDate<<endl;
}

void Date::setDefault(unsigned int d, Month m, unsigned int y)
{
   defaultDate=Date(d, m, y);
}

void Date::setDefault()
{
   struct tm* today=new tm;
   time_t timer;
   time(&timer);
   today=gmtime(&timer);
   defaultDate._day=today->tm_mday;
   defaultDate._month=++(today->tm_mon);
   defaultDate._year=today->tm_year+=1900;
}

const string Date::getMonthName() const{
	return monthNames[_month-1];
}

ostream& operator<<(ostream& os, const Date& d)
{
   os<<d.day()<<' '<<d.getMonthName()<<
      ' '<<d.year();
   return os;
}

ostream& operator<<(ostream& os, const Date::BadDate& bd)
{
   os<<bd.day()<<' '<<bd.month()<<
      ' '<<bd.year();
   return os;
}