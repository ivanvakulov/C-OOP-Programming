//Vakulov
//3/4/2017
#include "Time.h"

int main(){

	Time a(1,20,23);
	cout<<"Time a - "<<a<<endl;
	Time b(a);
	cout<<"Time b(copy of A) - "<<b<<endl;
	cout<<"B hours = "<<b.hours()<<endl;
	cout<<"B minutes = "<<b.minutes()<<endl;
	cout<<"B seconds = "<<b.seconds()<<endl;
	b.setHours(12);
	b.setMinutes(30);
	b.setSeconds(20);
	cout<<"Now B hours = "<<b.hours()<<endl;
	cout<<"Now B minutes = "<<b.minutes()<<endl;
	cout<<"Now B seconds = "<<b.seconds()<<endl;
	cout<<"Now Time b - "<<b<<endl;
	cout<<"static_cast<int>(b) - "<<(int)b<<"s"<<endl;
	cout<<"static_cast<double>(b) - "<<static_cast<double>(b)<<endl;
	Time c = b;
	cout<<"Time c = b, c - "<<c<<endl;
	cout<<"++c, now c = "<<++c<<endl;
	cout<<"c++ - "<<c++<<endl;
	cout<<"Now c - "<<c<<endl;
	cout<<"--c, now c = "<<--c<<endl;
	cout<<"c-- - "<<c--<<endl;
	cout<<"Now c - "<<c<<endl;
	cout<<"b + c = "<<b+c<<endl;

	Time test(59,59,23);
	cout<<"Test - "<<test;
	cout<<", ++test - "<<++test<<endl;
	cout<<"Test - "<<test;
	cout<<", --test - "<<--test<<endl;

	Date d(3,4,2017);
	Time t(0,23,19);
	Time i(05,00,00);
	timer(d,t,i);

	try{
		Time bad(-1,-2,-3);
	} catch (Time::BadTime bt){
		cerr<<"Bad time - "<<bt<<endl;
	}

	return 0;
}