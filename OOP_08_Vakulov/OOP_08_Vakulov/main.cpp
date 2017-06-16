//Vakulov
//3/24/2017
#include "Screen.h"

int main(){
	/*const int size=10;
	Screen demo(size, size);
	cout<<"Empty screen created !"<<endl<<endl;
	demo.show();
	for(int i = 0; i<=size; i++){
	   demo.set('*').move(i, i);
	}
	cout<<"The screen filled !"<<endl<<endl;
	demo.show();
	cout<<"Current - ";
	demo.showCurrent();
	cout<<endl;
	demo.set('&');
	cout<<"Now current - ";
	demo.showCurrent();
	cout<<endl<<endl;
	cout<<"<< for Screen - "<<endl<<demo<<endl;
	cout<<"Move - "<<endl;
	demo.move();
	demo.show();
	cout<<"Back - "<<endl;
	demo.back();
	demo.show();
	cout<<"Move(5,5) - "<<endl;
	demo.move(5,5);
	demo.show();
	cout<<"Home - "<<endl;
	demo.home();
	demo.show();
	cout<<"Clear - "<<endl;
	demo.clear();
	demo.show();
	const Screen demo2(size, size);
	cout<<"Empty const screen created !"<<endl<<endl;
	demo2.show();
	cout<<"Move(5,2) - "<<endl;
	demo2.move(5,2);
	demo2.show();
	cout<<"Move - "<<endl;
	demo2.move();
	demo2.show();
	cout<<"Back - "<<endl;
	demo2.back();
	demo2.show();
	cout<<"Home - "<<endl;
	demo2.home();
	demo2.show();
	cout<<"Current - ";
	demo.showCurrent();
	cout<<endl;
	cout<<endl<<"====================NON CONST======================"<<endl<<endl;
	const NonConstAction menuNonConst[] = {
		&Screen::home,
		&Screen::move,
		&Screen::back,
		&Screen::set,
		&Screen::show
	};
	Screen first (7,7);
	int repeat = 1;
	int act = 0;
	int amount = 0;
	while(repeat == 1){
		cout<< "What do you want to do? {0(home), 1(move), 2(back), 3(set(*)), 4(show)}"<<endl;
		cin >> act;
		cout << "Amount of times ?";
		cin >> amount;
		doActionNonConst(first,menuNonConst[act],amount);
		first.show();
		cout<<"Repeat?(1/0)";
		cin >> repeat;
	}
	cout<<endl<<"======================CONST======================"<<endl<<endl;
	const ConstAction menuConst[] = {
		&Screen::home,
		&Screen::move,
		&Screen::back,
		&Screen::show
	};
	const Screen second (7,7);
	int repeat2 = 1;
	int action2 = 0;
	int amount2 = 0;
	while(repeat2 == 1){
		cout<< "What do you want to do? {0(home), 1(move), 2(back), 3(show)}"<<endl;
		cin >> action2;
		cout << "Amount of times ?";
		cin >> amount2;
		doActionConst(second,menuConst[action2],amount2);
		second.show();
		cout<<"Repeat?(0/1)";
		cin >> repeat2;
	}*/
	Screen s(5,5,"fghrtbn");
	s.show();
	return 0;
}