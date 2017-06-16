//Vakulov
//Date date(25,2,2017);
#include "Date.h"

int main(){

	try {
		cout<<"Default date - ";
		Date::showDefault();

		Date::setDefault(15,Date::Month(5),1995);
		cout<<"Now Default date - ";
		Date::showDefault();

		Date::setDefault();
		cout<<"Now again Default date - ";
		Date::showDefault();

		Date d, d1(14, 10, 1991), d2(d1);
		cout<<"Three dates created - "<<d<<", "<<d1<<", "<<d2<<endl;
		Date x(26, 2, 2008);
		cout<<"One more date(X) created - "<<x<<endl;
		x.setMonth(2);
		cout<<"Month set(02)"<<endl;
		x.setDay(29);
		cout<<"Day set(29)"<<endl;
		x.setYear(2012);
		cout<<"Year set(2012)"<<endl;
		cout<<"X now - "<<x<<endl<<endl;
		Date y(x);
		cout<<"Y is a compy of X - "<<x<<endl<<endl;
		cout<<"++Y - "<<++y<<endl;
		cout<<"--Y - "<<--y<<endl<<endl;
		cout<<"Y++ - "<<y++<<endl;
		cout<<"Y now = "<<y<<endl;
		cout<<"Y-- - "<<y--<<endl;
		cout<<"Y now = "<<y<<endl;
		cout<<"Y day - "<<y.day()<<endl<<endl;
		cout<<"Y month - "<<y.month()<<endl;
		cout<<"Y month name - "<<y.getMonthName()<<endl;
		cout<<"Y year - "<<y.year()<<endl;
		Date testBad(55,12,2013);
	} catch (Date::BadDate bd){
		cerr<<"Bad date - "<<bd<<endl;
	}
	return 0;
}