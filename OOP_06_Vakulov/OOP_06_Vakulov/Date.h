//Vakulov
//3/4/2017
//Vakulov
//Date date(25,2,2017);
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Date
{
	public:
		struct BadDate;
		// to avoid problem 7.2.2002 7 feb or jul 2?
		enum Month {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
		Date (unsigned int d=0, Month m=Month(0),unsigned int y=0);
		Date (unsigned int d,unsigned int m,unsigned int y);
		Date (const Date&);
		~Date();
		inline int day() const{return _day;}
		inline Month month() const{return Month(_month);}
		inline int year() const{return _year;}
		const string getMonthName() const;
		void setDay(unsigned int);
		void setMonth(unsigned int);
		void setYear(unsigned int y);
		static void setDefault(unsigned int,Month,unsigned int);
		static void setDefault();
		static void showDefault();
		const Date& operator++();
		const Date  operator++(int);
		const Date& operator--();
		const Date  operator--(int);
	private:
		int _day, _month, _year;
		bool leapYear(int y);
		void fillDate(unsigned int d, Month m,unsigned int y);
		int amountOfDays();
		static string monthNames [12];
		static bool defaultSet;
		static Date defaultDate;
};
ostream& operator<<(ostream& os, const Date & d);
struct Date::BadDate
{
	int _day, _month, _year;
	inline int day() const{return _day;}
	inline int month() const{return _month;}
	inline int year() const{return _year;}
	BadDate(int d, int m, int y):_day(d), _month(m), _year(y){};
};
ostream& operator<<(ostream& os, const Date::BadDate & bd);