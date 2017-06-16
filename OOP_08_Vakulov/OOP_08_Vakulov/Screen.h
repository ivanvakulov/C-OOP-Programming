//Vakulov
//3/24/2017
#include <iostream>
using namespace std;

class Screen
{
public:
	Screen(int, int, char* pc =0);
	~Screen();

	const Screen& home() const;
	Screen& home();

	const Screen& move() const;
	Screen& move();

	const Screen& back() const;
	Screen& back();

	const Screen& show() const;
	Screen& show();

	const Screen& move(int a, int b) const;
	Screen& move(int a, int b);

	const Screen& move(int a) const;
	Screen& move(int a);

	Screen& clear();

	const Screen& showCurrent() const;

	char get() const;

	Screen& set(char);
	Screen& set();

	inline const int& cursor() const{return _cursor;}
	inline const int& height() const{return _height;}
	inline const int& width() const{return _width;}
private:
	static const int maxHeight;
	static const int maxWidth;
	static const char _filler;
	int _height;
	int _width;
	char *_wContent;
	mutable int _cursor;
	Screen(const Screen&);
	Screen& operator= (const Screen&);
};

ostream& operator<<(ostream&, const Screen&);
typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();
void doActionConst(const Screen& s, ConstAction act, int n);
void doActionNonConst(Screen& s, NonConstAction act, int n);