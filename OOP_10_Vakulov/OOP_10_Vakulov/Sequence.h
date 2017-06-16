//Vakulov
//4/8/2017

#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "Array.h"

template<typename Elem>
class Sequence{
public:
	class BadSeq{
	private:
		string _reason;
		size_t _index;
	public:
		BadSeq(string reason="unknown", size_t index=0): 
			 _reason(reason), _index(index){
			return;
		};
		~BadSeq() {};
		void diagnose() const
		{
			cout << _reason;
			if(_index!=0)
				cout<<", index = "<<_index;
			cout<<endl;
			return;
		}
	};

	explicit Sequence(const size_t capacity = _default) : _size(0),_allocator(new Array<Elem>(capacity)){
#ifndef NDEBUG
		cout << "Sequence - "<<this<<", type - "<<typeid(Elem).name()<<" created!"<<endl;
#endif
	}

	~Sequence(){
		delete _allocator;
#ifndef NDEBUG
		cout << "Sequence - "<<this<<", type - "<<typeid(Elem).name()<<" deleted!"<<endl;
#endif
	}
	
	size_t Sequence::capacity() const{
	   return _allocator->size();
	}

	inline size_t sizes() const{return _size;}

	bool empty() const{return (sizes()==0);}

	bool full() const{return sizes() == capacity();}

	Sequence& clear(){
		_size = 0;
		return *this;
	}

	const Elem& operator[](const size_t index) const{
		if(empty())
			throw BadSeq("Try to manipulate the empty sequence");
		if(index>=_size)
			throw BadSeq("Try to access a non existing element of the sequence",index+1); 
		return (*_allocator)[index];
	}

	Elem& operator[]( const  size_t index){
		if(empty())
			throw BadSeq("Try to manipulate the empty sequence");
		if(index>=_size)
			throw BadSeq("Try to access a non existing element of the sequence",index+1); 
		return (*_allocator)[index];
	}

	Sequence& add(const Elem& elem)	{
		return doinsert(elem, _size);
	}

	Sequence& insert(const Elem& elem, const size_t index){
		if(_size<index)
			throw BadSeq("Try to insert after a non existing element of the sequence", index+1);
		return doinsert(elem, index);
	}

	Sequence& cut(){
		return doremove(_size);
	}

	Sequence& remove(const size_t index){
		if((_size<index)||(index==0)
			throw BadSeq("Try to delete a non existing element of the sequence",index+1); 
		return doremove(index);
	}

	bool contains(const Elem& elem){
		for(size_t i = 0;i<_size;++i){
			if((*_allocator)[i] == elem) return true;
		}
		return false;
	}

	void check(bool check){
		if(check){
			(*this).enlarge();
		}else{
			(*this).reduce();
		}
	}
private:
	size_t _size;
	static const size_t _default = 0;
	Array<Elem> * _allocator;

	void reduce(const size_t times = 2){
		Array<Elem> *newArray = new Array<Elem>(capacity()/times);
		for (size_t i=0; i<_size; i++)
			(*newArray)[i]=(*_allocator)[i];
		delete _allocator;
		_allocator=newArray;
	}

	void enlarge(const size_t times = 2){
		Array<Elem> *newArray = new Array<Elem>(times*capacity());
		for (size_t i=0; i<_size; i++)
			(*newArray)[i]=(*_allocator)[i];
		delete _allocator;
		_allocator=newArray;
	}

	Sequence& doinsert(const Elem& elem,const size_t index){
		if(_size+1>capacity())
			enlarge();
		++_size;
		for (size_t i=_size-1; i>index; --i)
			(*_allocator)[i] = (*_allocator)[i-1];
		(*_allocator)[index] = elem;
		return *this;
	}

	Sequence& doremove(const size_t index){
		if(empty())
			throw BadSeq("Try to manipulate the empty sequence");
		for (size_t i=index; (i<_size)&&(i>0); ++i)
			(*_allocator)[i-1] = (*_allocator)[i];
		--_size;
		return *this;
	}

	Sequence (const Sequence&);
	Sequence& operator=(const Sequence&);
};

template <typename T>
ostream &operator<<(ostream &os, const Sequence<T> &ar){
	size_t n = ar.sizes();
	char chr=' ';
	cout<<"Sequence of "<<n<<" elements, capacity = "<<ar.capacity()<<"\nLooks like:";
	if(ar.sizes()>0){
		for(size_t i=0; i<n; ++i){
			cout<<chr<<ar[i];
			if(chr=' ')chr=',';
		}
	}else{
		cout<<" Empty";
	}
	cout<<'.'<<endl;
	return os;
}



#endif