//Vakulov
//4/8/2017

#include "Sequence.h"

int main(){
	/*Sequence<int> a(10);
	cout<<"The capacity of first sequence - "<<a.capacity()<<"\n";
	cout<<"The size of first sequence - "<<a.sizes()<<"\n";
	cout<<"Is the first sequence empty? - "<<a.empty()<<"\n";
	cout<<"Is the first sequence full? - "<<a.full()<<"\n";

	try{
		cout<<a[3]<<"\n";
	}catch(Sequence<int>::BadSeq& bq){
		bq.diagnose();
	}
	
	try{
		a.add(4);
		a.add(5);
		cout<<a;
		a.add(6);
		a.insert(9,2);
		cout<<a;
		a.cut();
		cout<<a;
		a.add(10);
		cout<<a;
		a.remove(2);
		cout<<a;
	}catch(Sequence<int>::BadSeq& bq){
		bq.diagnose();
	}

	try{
		cout<<"The third element is - "<<a[2]<<"\n";
		cout<<"The eleventh element is - "<<a[10]<<"\n";
	}catch(Sequence<int>::BadSeq& bq){
		bq.diagnose();
	}
	cout<<"Does sequence contains 10? - "<<a.contains(10)<<"\n";
	cout<<"Does sequence contains 11? - "<<a.contains(11)<<"\n";
	a.clear();
	cout<<"The sequence was cleared!\n";
	cout<<a;
	cout<<"===========CHECKING========\n";
	Sequence<double> b(15);
	b.add(2.46);
	b.add(5.5);
	b.add(33.4);
	b.insert(2.2,1);
	cout<<b;
	b.check(true);
	cout<<b;
	b.check(false);
	cout<<b;
	Sequence<double> c(1);
	cout<<"Capacity now - "<<c.capacity()<<"\n";
	c.add(4);
	c.add(5);
	c.add(3);
	cout<<"Capacity now - "<<c.capacity()<<"\n";*/
	Sequence<int> seq(5); 
	seq.add(1).add(2).add(3).add(4).add(5); 
	size_t expected_size = 5;
	cout<<seq[0];
	seq.remove(0);
	return 0;
}