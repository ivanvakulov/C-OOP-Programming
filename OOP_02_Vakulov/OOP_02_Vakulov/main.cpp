//Vakulov Ivan 
//04-02-2017
#include "segment.h"

int main(){

	Point a(5,6);
	Point b(3,4);
	Point c(10,10);
	cout<<endl;
	Segment s1(a,b);
	cout<<endl;
	cout<<s1<<endl;
	cout<<"Length of s1 = "<< s1.length() <<endl;
	cout<<"Distance to point "<<c<<" = "<<s1.distance(c)<<endl<<endl;
	Segment s2(1,3,4,5);
	cout<<endl;
	cout<<s2<<endl;
	cout<<"Length of s2 = "<< s2.length() <<endl;
	cout<<"Distance to point "<<c<<" = "<<s2.distance(c)<<endl<<endl;
	Segment s3 = s2;
	cout<<s3<<endl<<endl;
	Segment x; Point two(2); cout<<x<<'_'<<two<<':'<<x.distance(two)<<endl;
	return 0;
}