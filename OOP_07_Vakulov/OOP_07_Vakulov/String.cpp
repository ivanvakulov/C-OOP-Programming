//Vakulov
//3/19/2017
#include "String.h"


String:: String() :_len(0), _allocator(new char [_len+1]){
	_allocator[0] = '\0';
#ifndef NDEBUG
	cout << "Empty String created - [" << this << "]"<<endl;
#endif
}

String:: String(const char* c){
	if(c == 0) 
		throw BadString("Null pointer exception!");
	_len = strlen(c);
	_allocator = new char [_len+1];
	strcpy(_allocator,c);
#ifndef NDEBUG 
	cout << "String created - [" << this << "]"<<endl; 
#endif 
}

String::String(const char c): _len(2),_allocator(new char[_len+1]){
#ifndef NDEBUG 
	cout << "String created - [" << this << "]"<<endl; 
#endif 
	_allocator[0] = c;
	_allocator[1] = '\0';
}

String::String(const string& s):  _len(s.length()), _allocator(new char[_len+1]){
	strcpy(_allocator, s.c_str());
#ifndef NDEBUG 
	cout << "String created - [" << this << "]"<<endl; 
#endif 
}

String:: ~String(){
	delete [] _allocator;
#ifndef NDEBUG
	cout << "String deleted - [" << this << "]"<<endl;
#endif
}

String:: String(const String& s, int multiplayer):_len(s._len*multiplayer), _allocator(new char [_len+1]){
	char* target=_allocator;
	for(int i=0; i<multiplayer; i++){
		strcpy(target, s._allocator);
		target+=s._len;
	}
#ifndef NDEBUG 
	cout << "String created - [" << this << "]"<<endl; 
#endif 
	return;
}

String::operator string() const{
#ifndef NDEBUG
	cout<<"String "<<this<<" casted to string!"<<endl;
#endif
	return string(_allocator);
}

const string String::STL_string() const{
	return string(_allocator);
}

String& String::operator=(const String& s)
{
   if(this==&s)
      return *this;
   delete [] _allocator;
   _len=s._len;
   _allocator=new char[_len+1];
   strcpy(_allocator, s._allocator);
   return *this;
}

String& String::operator=(const string& s)
{
   delete [] _allocator;
   _len=s.length();
   _allocator=new char[_len+1];
   strcpy(_allocator, s.c_str());
   return *this;
}

String& String::operator=(const char* ps)
{
	if(ps==0)
		throw BadString("Null pointer exception!");
   if(ps==0)
		return *this;
   delete [] _allocator;
   for(_len=0; ps[_len]; _len++);
   _allocator=new char[_len+1];
   strcpy(_allocator, ps);
   return *this;
}

String& String::operator=(const char c)
{
   delete [] _allocator;
   _len=1;
   _allocator=new char[2];
   _allocator[0]=c;
   _allocator[1]='\0';
   return *this;
}

char& String::operator[](size_t i)
{
   if(_len<=i)
      throw BadIndex(i);
   return _allocator[i];
};

const char& String::operator[](size_t i) const
{
   if(_len<=i)
      throw BadIndex(i);
   return _allocator[i];
}

bool String::operator==(const String& s) const
{
	bool equal = _len == s.length();
   for(int i=0; (i<_len)&&equal; i++)
      equal=*(_allocator+i)==*(s._allocator+i);
   return equal;
}

bool String::operator!=(const String& s) const
{
   return !(*this==s);
}

bool String::operator<(const String& s) const
{
   bool res=true;
   int i=0;
   while(res&&(i<_len)&&(i<s._len)) 
   {
      res=res&&(*(_allocator+i)==*(s._allocator+i));
      i++;
   }
   if(res)
      return _len<s._len;
   i--;
   return *(_allocator+i)<*(s._allocator+i);
}

bool String::operator>(const String& s) const{
	return !(*this<=s);
}

bool String::operator<=(const String& s) const
{
    if(*this==s)
       return true;
    return *this<s;
}
bool String::operator>=(const String& s) const
{
	if(*this==s)
       return true;
	return *this>s; 
}

String& String::operator+=(const String& s)
{
   size_t len=_len+s._len;
   char* newAllocator=new char[len+1];
   strcpy(newAllocator, _allocator);
   delete [] _allocator;
   _allocator=newAllocator;
   strcpy(_allocator+_len, s._allocator);
   _len=len;
   return *this;
}

String& String::operator+=(const string& s)
{
	size_t len=_len+s.length();
   char* newAllocator=new char[len+1];
   strcpy(newAllocator, _allocator);
   delete [] _allocator;
   _allocator=newAllocator;
   strcpy(_allocator+_len, s.c_str());
   _len=len;
   return *this;
}

String String::operator+(const String& s) const{
	String res(*this);
	return res+=s;
}

String& String::operator+=(const char* ps)
{
   if(ps==0)
	   return *this;
   size_t len=strlen(ps);
   char* newAllocator=new char[len+_len+1];
   strcpy(newAllocator, _allocator);
   delete [] _allocator;
   _allocator=newAllocator;
   strcpy(_allocator+_len, ps);
   _len+=len;
   return *this;
}

ostream& operator<<(ostream& os, const String& s)
{
   for(int i=0; i<s.length(); i++)
      os<<s[i];
   return os;
}