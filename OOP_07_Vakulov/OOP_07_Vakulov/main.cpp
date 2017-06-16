//Vakulov
//3/19/2017
#include "String.h"

int main(){
	
	try{
		String first;
		cout<<"Empty string created - "<<first<<endl;
		char* c = new char[5];
		c[0] = 'k';
		c[1] = 'v';
		c[2] = 'i';
		c[3] = 't';
		c[4] = 't';
		c[5] = '\0';
		String d(c);
		cout<<"String from char* created - "<<d<<endl;
		string a("sdf");
		String b(a);
		cout<<"String from string created - "<<b<<endl;
		cout<<"B length = "<<b.length()<<endl;
		String f(b,2);
		cout<<"Multy(2) copying of b - "<<f<<endl;
		String k('k');
		cout<<"String from char - "<<k<<endl;
		cout<<"Is k empty? - "<<k.empty()<<endl;
		k.clear();
		cout<<"Is k empty now? - "<<k.empty()<<endl;
		const char* test = b.c_str();
		string n = b.STL_string();
		String g = b;
		cout<<"String g = String b - "<<g<<endl;
		string l = "qwerty";
		g = l;
		cout<<"String g = string l - "<<g<<endl;
		g = 'g';
		cout<<"String g = char'g' - "<<g<<endl;
		g = c;
		cout<<"String g = char* c - "<<g<<endl;
		cout<<"g[0] - "<<g[0]<<endl;
		g[0] = 'a';
	    cout<<"now g[0] - "<<g[0]<<endl;
		b = g;
		cout<<"G - "<<g<<", B - "<<b<<endl;
		cout<<"g==b - "<<(g==b)<<endl;
		cout<<"g!=b - "<<(g!=b)<<endl;
		cout<<"g>b - "<<(g>b)<<endl;
		cout<<"g>=b - "<<(g>=b)<<endl;
		cout<<"g<b - "<<(g<b)<<endl;
		cout<<"g<=b - "<<(g<=b)<<endl;
		cout<<"G - "<<g<<", F - "<<f<<endl;
		cout<<"g<f - "<<(g<f)<<endl;
		cout<<"g>f - "<<(g>f)<<endl;
		cout<<"g+f - "<<(g+f)<<endl;
		g+=f;
		cout<<"g+=f(String), now g - "<<g<<endl;
		g+=c;
		cout<<"g+=c,(char* c) now g - "<<g<<endl;
		g+=a;
		cout<<"g+=a,(string a) now g - "<<g<<endl;
		String x(nullptr);
		
		
	}catch(String::BadString bs){
		bs.diagnose();
	}

	cout<<"=========CAST======="<<endl;
		string str("asdasdasd");
		String tester(str);
		string tester2("werwet");
		tester+=tester2;
		cout<<"String += string"<<tester<<endl;
	return 0;
}