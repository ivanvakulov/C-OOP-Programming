//Vakulov
//3/19/2017
#include <iostream>
#include <string>
using namespace std;
class String
{
	private:
		size_t _len;
		char* _allocator;
	public:
		class BadString;
		class BadIndex;
		String();
		explicit String(const char*);
		String(const char);
		explicit String(const string&);
		String(const String & s, int multiplayer = 1);
		~String();
		String& operator=(const String&);
		String& operator=(const string&);
		String& operator=(const char*);
		String& operator=(const char);
		const string STL_string() const;
		inline const char* c_str() const{return _allocator;}
		operator string() const;
		inline size_t length() const{return _len;}
		inline bool empty() const{return _len==0;}
		inline void clear(){*this = String();}
		char& operator[](size_t);
		const char& operator[](size_t) const;
		bool operator==(const String&) const;
		bool operator!=(const String&) const;
		bool operator< (const String&) const;
		bool operator<=(const String&) const;
		bool operator> (const String&) const;
		bool operator>=(const String&) const;
		String operator+(const String&) const;
		String& operator+=(const char*);
		String& operator+=(const String&);
		String& operator+=(const string&);
};
ostream& operator<<(ostream&, const String&);

class String::BadString
{
private:
   string _reason;
public:
   BadString(string reason=""):_reason(reason){
      return;
   };
   ~BadString() {};
   void diagnose() const{
      cerr<<_reason<<endl;
   }
};

class String::BadIndex
{
private:
   size_t _index;
public:
   BadIndex(size_t index=0): _index(index){
      return;
   };
   ~BadIndex() {};
   void diagnose() const{
         cerr<<"Bad index: "<<_index;
         cerr<<endl;
   }
};