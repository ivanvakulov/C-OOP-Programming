//Vakulov
//4/2/2017
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <string>
#include <iostream>
using namespace std;

template<typename T>
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

	Array(size_t n=0):_allocator(new T[n]),_start(_allocator), _cur(_start), _end(_start+n),_size(n){
#ifndef NDEBUG
		cout << "Array - "<<this<<", type - "<<typeid(T).name()<<" created!"<<endl;
#endif
	}	

	Array(size_t n, const T& a):_allocator(new T[n]),_start(_allocator), _cur(_start), _end(_start+n),_size(n){
		fill(a);
#ifndef NDEBUG
		cout << "Array - "<<this<<", type - "<<typeid(T).name()<<" created and filled with - "<<a<<endl;
#endif
	}

	Array(const Array& a):_allocator(new T[a.size()]),_start(_allocator), _cur(_start), _end(_start+a.size()),_size(a.size()){
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
		if(index >= _size){
			throw BadArray("Bad index - ",index);
		}
		return _allocator[index];
	}

	const T& operator[](size_t index) const{
		if(index >= _size){
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
		for(size_t i = 0;i<_size;i++){
			_allocator[i] = a;
		}
	}

	Array<T>& operator=(const Array<T>& a){
		if(this!=&a){
			for(size_t i = 0;i<a.size();i++){
				_allocator[i] = a[i];
			}
		}
		return *this;
	}

	const size_t size() const{return _size;}
private:
	size_t _size;
	T * _allocator;
	T * _start;
	T * _end;
	mutable T * _cur;
};

template <typename T>
ostream &operator<<(ostream &os, const Array<T> &ar){
	size_t n = ar.size();
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