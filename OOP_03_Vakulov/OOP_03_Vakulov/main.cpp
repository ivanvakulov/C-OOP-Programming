//Vakulov Ivan
//2/11/2017
#include "acomp.h"
#include "tcomp.h"
int main(){
	cout<<endl;

	cout<<"===================================ACOMPLEX====================================="<<endl;
	AComplex a(1,2);
	AComplex b(a);
	AComplex c(3,4);
	b = c;
	cout<<"AComplex with id: "<<b.getId()<<" - re = "<<b.re()<<", im = "<<b.im()<<endl;
	b.re() = 5;
	b.im() = 6;
	cout<<"Now AComplex with id: "<<b.getId()<<" = "<<b<<endl;
	cout<<"AComplex with id: "<<b.getId()<<", module = "<<b.mod()<<", argument = "<<b.arg()<<", conjugate = "<<b.conj()/*Conjuate AComplex will be deleted immediately*/<<endl;
	AComplex d(b);
	cout<<"AComplex with id: "<<b.getId()<<" = " <<b<<endl;
	/*cin>>b;
	cout<<b<<endl;*/

	cout<<endl<<endl;

	cout<<"================================OPRATIONS ACOMPLEX=============================="<<endl;
	AComplex ab = a+b;
	cout<<a<<" + "<<b<<" = "<<ab<<endl;
	cout<<a;cout<<" += "<<b<<" = "<<(a+=b)<<endl;
	cout<<ab<<" == "<<a<<" - "<<bool(ab==a)<<endl;
	cout<<b<<" - "<<a<<" = "<<b-a<<endl;
	cout<<c<<" + "<<d<<" = "<<c+d<<endl;
	AComplex dc = d-c;
	cout<<d<<" - "<<c<<" = "<<d-c<<endl;
	cout<<d;cout<<" -= "<<c<<" -= "<<(d-=c)<<endl;
	cout<<dc<<" == "<<d<<" - "<<bool(dc==d)<<endl;
	cout<<endl;
	int p = 2;
	cout<<a<<"^"<<p<<" = "<<power(a,p)<<endl;
	++p;
	cout<<b<<"^"<<p<<" = "<<power(b,p)<<endl;
	cout<<endl<<endl;

	cout<<"=============================BOOL OPERANDS ACOMPLEX============================="<<endl;
	cout<<a<<" == "<<b<<" - "<<bool(a==b)<<endl;
	cout<<a<<" != "<<b<<" - "<<bool(a!=b)<<endl;
	cout<<b<<" == "<<d<<" - "<<bool(b==d)<<endl;
	cout<<b<<" != "<<d<<" - "<<bool(b!=d)<<endl;
	cout<<d<<" == "<<c<<" - "<<bool(d==c)<<endl;
	cout<<c<<" != "<<a<<" - "<<bool(c!=a)<<endl;

	cout<<endl<<endl;
	
	cout<<"===================================TCOMPLEX====================================="<<endl;
	TComplex m(3.14,5);
	TComplex v(m);
	cout<<"TComplex with id: "<< v.getId() << " = " << v <<endl;
	TComplex z = v;
	cout<<"TComplex with id: "<<z.getId()<<", mod = "<<z.mod()<<", arg = "<<z.arg()<<endl;
	z.mod() = 1;
	z.arg() = 6;
	cout<<"Now TComplex with id: "<<z.getId()<<", mod = "<<z.mod()<<", arg = "<<z.arg()<<endl;
	/*cin>>m;
	cout<<m<<endl;*/
	cout<<endl<<endl;

	cout<<"=============================OPRATIONS TCOMPLEX================================="<<endl;
	TComplex ts = m*z;
	cout<<m<<" * "<<z<<" = "<<ts<<endl;
	cout<<m;cout<<" *= "<<z<<" = "<<(m*=z)<<endl;
	cout<<ts<<" == "<<m<<" - "<<bool(ts==m)<<endl;
	cout<<z<<" * "<<v<<" = "<<z*v<<endl;
	TComplex tz = m/z;
	cout<<m<<" / "<<z<<" = "<<tz<<endl;
	cout<<m;cout<<" /= "<<z<<" = "<<(m/=z)<<endl;
	cout<<tz<<" == "<<m<<" - "<<bool(tz==m)<<endl;
	cout<<z<<" / "<<v<<" = "<<z/v<<endl;
	cout<<endl;
	int o = 2;
	cout<<m<<"^"<<o<<" = "<<power(m,o)<<endl;
	++o;
	cout<<z<<"^"<<o<<" = "<<power(z,o)<<endl;
	
	cout<<endl<<endl;

	/*cout<<"===================================CASTING======================================"<<endl;
	AComplex testA(4,8);
	TComplex testB = (TComplex) testA;
	cout<<"AComplex with id: "<<testA.getId()<<" - re = "<<testA.re()<<", im = "<<testA.im()<<endl;
	cout<<"TComplex with id: "<<testB.getId()<<" - re = "<<testB.re()<<", im = "<<testB.im()<<endl;

	cout<<endl<<endl;

	TComplex testC(3.14,7);
	AComplex testD = (AComplex) testC;
	cout<<"TComplex with id: "<<testC.getId()<<" - mod = "<<testC.mod()<<", arg = "<<testC.arg()<<endl;
	cout<<"AComplex with id: "<<testD.getId()<<" - mod = "<<testD.mod()<<", arg = "<<testD.arg()<<endl;

	cout<<endl<<endl;

	cout<<"===============================SPECIAL CASTING=================================="<<endl;
	cout<<"===========================SPECIAL BOOL OPERATIONS=============================="<<endl;
	TComplex n(3.14,2);
	AComplex l(5,6);
	cout<<n<<" == "<<l<<" - "<<bool(n==l)<<endl;
	cout<<n<<" != "<<l<<" - "<<bool(n!=l)<<endl;
	TComplex x(l);
	cout<<(AComplex)x<<" == "<<l<<" - "<<bool((AComplex)x==l)<<endl;//funny moment (4.9999999999999991 != 5.0000000000000000  inaccurate double) (discovered with debugger)
	cout<<(AComplex)x<<" != "<<l<<" - "<<bool((AComplex)x!=l)<<endl;
	cout<<endl<<endl;
	cout<<"=============================SPECIAL OPERATIONS================================="<<endl;
	cout<<"TComplex "<< n<<" + ACompex "<<l<<" = "<<n+l<<endl;
	cout<<"TComplex "<< n<<" - ACompex "<<l<<" = "<<n-l<<endl;
	cout<<"TComplex "<< n<<" * ACompex "<<l<<" = "<<n*l<<endl;
	cout<<"TComplex "<< n<<" / ACompex "<<l<<" = "<<n/l<<endl;

	cout<<endl<<endl;*/
	cout<<"===================================CASTING======================================"<<endl;
	AComplex testA(4,8);
	TComplex testB (testA);
	cout<<"AComplex with id: "<<testA.getId()<<" - re = "<<testA.re()<<", im = "<<testA.im()<<endl;
	cout<<"TComplex with id: "<<testB.getId()<<" - re = "<<testB.re()<<", im = "<<testB.im()<<endl;

	cout<<endl<<endl;

	TComplex testC(3.14,7);
	AComplex testD(testC);
	cout<<"TComplex with id: "<<testC.getId()<<" - mod = "<<testC.mod()<<", arg = "<<testC.arg()<<endl;
	cout<<"AComplex with id: "<<testD.getId()<<" - mod = "<<testD.mod()<<", arg = "<<testD.arg()/*0.716815 = 7(period) atan2() returns first value*/<<endl;

	cout<<endl<<endl;

	cout<<"===============================SPECIAL CASTING=================================="<<endl;
	cout<<"===========================SPECIAL BOOL OPERATIONS=============================="<<endl;
	TComplex n(3.14,2);
	AComplex l(5,6);
	cout<<"TComplex "<<n<<" == "<<"AComplex "<<l<<" - "<<bool(n==l)<<endl;
	cout<<"TComplex "<<n<<" != "<<"AComplex "<<l<<" - "<<bool(n!=l)<<endl;

	cout<<endl<<endl;

	cout<<"=============================SPECIAL OPERATIONS================================="<<endl;
	cout<<"TComplex "<< n<<" + AComplex "<<l<<" = "<<n+l<<endl;
	cout<<"TComplex "<< n<<" - AComplex "<<l<<" = "<<n-l<<endl;
	cout<<"TComplex "<< n<<" * AComplex "<<l<<" = "<<n*l<<endl;
	cout<<"TComplex "<< n<<" / AComplex "<<l<<" = "<<n/l<<endl;

	cout<<endl<<endl;
#ifndef NDEBUG
	cout<<"==================================DELETING======================================"<<endl;
#endif
	return 0;
}