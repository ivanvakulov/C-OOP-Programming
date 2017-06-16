//Vakulov
//4/2/2017
#include <string>
#include <iostream>
using namespace std;
#ifndef _ARRAY_H_
#define _ARRAY_H_

template<size_t n, typename T>
class Array{
public:
	class BadArray{
	   private:
		  string _reason;
		  size_t _index;
	   public:
		  BadArray(string reason="unknown", size_t index=0): 
			 _reason(reason), _index(index){
			 return;
		  };
		  ~BadArray() {};
		  void diagnose() const
		  {
			 cout << _reason;
			 if(_index!=0)
				cout<<' '<<_index;
			 cout<<endl;
			 return;
		  }
	};

	Array():_allocator(new T[n]),_start(_allocator), _cur(_start), _end(_start+n){
#ifndef NDEBUG
		cout << "Array - "<<this<<", type - "<<typeid(T).name()<<" created!"<<endl;
#endif
	}	

	Array(const T& a):_allocator(new T[n]),_start(_allocator), _cur(_start), _end(_start+n){
		fill(a);
#ifndef NDEBUG
		cout << "Array - "<<this<<", type - "<<typeid(T).name()<<" created and filled with - "<<a<<endl;
#endif
	}

	Array(const Array& a):_allocator(new T[n]),_start(_allocator), _cur(_start), _end(_start+n){
#ifndef NDEBUG
		cout << "Array - "<<this<<", type - "<<typeid(T).name()<<" copied from - "<<&a<<endl;
#endif
	}

	~Array(){
		delete [] _allocator;
#ifndef NDEBUG
		cout << "Array - "<<this<<", type - "<<typeid(T).name()<<" deleted!"<<endl;
#endif
	}

	T& operator[](size_t index){
		if(index >= n){
			throw BadArray("Bad index - ",index);
		}
		return _allocator[index];
	}

	const T& operator[](size_t index) const{
		if(index >= n){
			throw BadArray("Bad index - ",index);
		}
		return _allocator[index];
	}

	void start() const {_cur = _start;}

	void next() const {++_cur;}

	bool stop() const {return (_cur == _end);}

	const T& elem() const{return * _cur;}

	T& elem() {return * _cur;}

	void fill(const T& a){
		for(size_t i = 0;i<n;i++){
			_allocator[i] = a;
		}
	}

	Array<n,T>& operator=(const Array<n,T>& a){
		if(this!=&a){
			for(size_t i = 0;i<n;i++){
				_allocator[i] = a[i];
			}
		}
		return *this;
	}
private:
	T * _allocator;
	T * _start;
	T * _end;
	mutable T * _cur;
};

template <size_t n, typename T>
ostream &operator<<(ostream &os, const Array<n, T> &ar){
	char chr=' ';
	cout<<"Array of "<<n<<" elements:";
	for(size_t i=0; i<n; ++i)
	{
		cout<<chr<<ar[i];
		if(chr=' ')chr=',';
	}
	cout<<'.'<<endl;
	return os;
}
#endif