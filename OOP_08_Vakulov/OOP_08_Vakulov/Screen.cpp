//Vakulov
//3/24/2017
#include "Screen.h"

const int Screen::maxHeight=24;
const int Screen::maxWidth=80;
const char Screen::_filler='.';

Screen::Screen(int m, int n, char *s):_width(m>maxWidth? maxWidth :m), _height(n>maxHeight? maxHeight :n), _cursor(0){
   int lens = s == 0 ? 0 : strlen(s);
   int len = lens > _height * _width ? _height * _width : lens;
   _wContent=new char [_height*_width+1];
   _wContent[_height*_width]='\0';
   int k=0;
   if(s!=0)
      for(; k<len; k++)
         *(_wContent+k)=*s++;
   for(; k<_height*_width; k++)
      *(_wContent+k)=_filler;
#ifndef NDEBUG
   cout<<"Screen created - "<<this<<" !"<<endl;
#endif
}

Screen::~Screen(){
   delete [] _wContent;
#ifndef NDEBUG
   cout<<"Screen deleted - "<<this<<" !"<<endl;
#endif
}

const Screen &Screen::home() const{
   _cursor=0;
   return *this;
}

Screen &Screen::home(){
   _cursor=0;
   return *this;
}

const Screen& Screen::move() const{
   if((++_cursor)>=_width*_height)_cursor=0;
   return *this;
}

Screen& Screen::move(){
	if((++_cursor)>=_width*_height)_cursor=0;
    return *this;
}

const Screen& Screen::back() const{
   if(--_cursor<0)_cursor=0;
   return *this;
}

Screen& Screen::back(){
   if(--_cursor<0)_cursor=0;
   return *this;
}

const Screen &Screen::show() const
{
   int cursor=_cursor;
   cout<<"cursor="<<_cursor<<endl;
   home();
   for(int i=0; i<_height; i++){
      for(int j=0; j<_width; j++){
		cout<<get();
		move();
      }
      cout<<endl;
   }
   _cursor=cursor;
   return *this;
}

Screen& Screen::show(){
   int cursor=_cursor;
   cout<<"cursor="<<_cursor<<endl;
   home();
   for(int i=0; i<_height; i++){
      for(int j=0; j<_width; j++){
		cout<<get();
		move();
      }
      cout<<endl;
   }
   _cursor=cursor;
   return *this;
}

const Screen &Screen::move(int i, int j) const{
   if((i>=_height)||(j>=_width))
      _cursor=0;
   else
      _cursor=_width*i+j;
   return *this;
}

const Screen &Screen::move(int i) const{
   if(i>=_height*_width)
      _cursor=0;
   else
      _cursor=i;
   return *this;
}

Screen& Screen::move(int i, int j){
   if((i>=_height)||(j>=_width))
      _cursor=0;
   else
      _cursor=_width*i+j;
   return *this;
}

Screen& Screen::move(int i){
   if(i>=_height*_width)
      _cursor=0;
   else
      _cursor=i;
   return *this;
}

Screen &Screen::clear(){
   for(int i=0; i<_height*_width; i++)
      *(_wContent+i)=_filler;
   _cursor=0;
   return *this;
}

char Screen::get() const
{
   return *(_wContent+_cursor);
}

Screen &Screen::set(char a) 
{
   *(_wContent+_cursor)=a;
   return *this;
}

Screen &Screen::set() 
{
   *(_wContent+_cursor)='*';
   return *this;
}

const Screen& Screen::showCurrent() const{
	cout<< get();
	return *this;
}

void doActionConst
   (const Screen &s, ConstAction act, int n)
{
   for(int i=0; i<n; i++)
      (s.*act)();
}

void doActionNonConst
   (Screen &s, NonConstAction act, int n)
{
   for(int i=0; i<n; i++)
      (s.*act)();
}

ostream& operator<<(ostream& os, const Screen& s){
	int cursor=s.cursor();
    s.home();
    for(int i=0; i<s.height(); i++){
		for(int j=0; j<s.width(); j++){
		os<<s.get();
		s.move();
      }
      os<<endl;
    }
	s.move(cursor);
	return os;
}