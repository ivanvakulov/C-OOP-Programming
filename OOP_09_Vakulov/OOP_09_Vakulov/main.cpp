//Vakulov
//4/2/2017
#include "Array.h"
#include "point.h"
int main(){

	try{
		cout<<"Error should be here!"<<endl;
		Array<5,int> arr;
		arr.fill(5);
		cout<<arr;
		arr[0] = 4;
		arr[1] = 5;
		arr[2] = 2;
		arr[3] = 4;
		arr[4] = 5;
		arr[5] = 10;
		cout<<arr;
	}catch(Array<5,int>::BadArray& ba){
		ba.diagnose();
	}
	Array<3,int> a;
	Array<3,int> b(a);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	int i = 0;
	cout<<"Changing elements using iterator:"<<endl;
	while(!b.stop()){
		cout<<b.elem()<<" ";
		b.elem() = i;
		++i;
		b.next();
	}
	cout<<endl;
	b.start();
	while(!b.stop()){
		cout<<b.elem()<<" ";
		b.next();
	}
	cout<<endl;
	Array<4,double> c(7);
	Array<4,double> d;
	d = c;
	cout<<c;
	cout<<d;

	Point x(5,5);
	Array<5,Point> test(x);
	cout<<"Array of Points !"<<endl;
	cout<<test;
	cout<<"Third element - "<<test[2]<<endl;
	Point f(1,2);
	test[2] = f;
	cout<<"Now Third element - "<<test[2]<<endl;
	cout<<"The whole array:"<<test<<endl;
	cout<<"Trying to use an element, that doesn't exist:"<<endl;
	try{
		test[6] = f;
	}catch(Array<5,Point>::BadArray& ba){
		ba.diagnose();
	}
	cout<<"Array of strings !"<<endl;
	Array<4,string> test2;
	test2.fill("Hello!");
	cout<<test2<<endl;
	int k = 1;
	cout<<"Changing elements using iterator:"<<endl;
	while(!test2.stop()){
		cout<<test2.elem()<<" ";
		test2.elem() = "Hello Iterator";
		++i;
		test2.next();
	}
	cout<<endl;
	test2.start();
	while(!test2.stop()){
		cout<<test2.elem()<<" ";
		test2.next();
	}
	cout<<endl;
	return 0;
}