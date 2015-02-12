#ifndef TUSTACK_H
#define TUSTACK_H

#include <iostream>
#include <string>

using namespace std ;



template <class T>

class TUStack
{
private:
	int size ; 
	int index;
	T *stack; 

public:
	TUStack();
	~TUStack();
	TUStack(const TUStack &obj) ;
	TUStack & operator=(const TUStack &obj);
	TUStack(int nSize);
	void Push(T item);
	T Pop();
	int Size();
	int Position();
	T& operator[] (int index);

	class NotInBounds
	{
	public:
		public:
		int index ; 
		int size ; 
		string message ; 

		NotInBounds(int thisindex, int thissize, string errorm)
		{
			index = thisindex;
			size = thissize;
			message = errorm;

		}

	} ; 

};

template<class T>
TUStack<T>::TUStack()
{
	size=0;
	stack= NULL;
	index=0;
}
template <class T>
TUStack<T>::~TUStack()
{	

	delete[] stack;

}

template<class T>
TUStack<T>::TUStack(int nSize)
{
	size = nSize;
	stack= new T[nSize];
	index = 0;
}

template <class T>
TUStack<T>::TUStack(const TUStack &obj)
{
	size = obj.size ;
	stack = new T[size] ;

	for (int i = 0 ; i < size ; i++)
	{

		stack[i] = obj.stack[i] ;

	}
}

template <class T>
TUStack<T> & TUStack<T>::operator=(const TUStack<T> &obj)
{
	size = obj.size;
	stack= new T[size];
	for (int i = 0 ; i < size ; i++)
	{
		stack[i] = obj.stack[i] ;
	}
	return *this;
}

template <class T>
int TUStack<T>::Size()
{
	return size;
}
template <class T>
int TUStack<T>::Position()
{
	return index;
}
template <class T>
void TUStack<T>::Push(T item)
{
	if (index >= size)
	{
		throw NotInBounds(index, size, "the stack is full");
	}
	else if (stack[index]== item)
		throw NotInBounds(index, size, "you are trying to push the same value on the stack");  
	 
	 stack[index] = item;
	 cout << "Index is " << index << ": Its stored information is " << stack[index] << endl << endl ;
	 index++;
}
template <class T>
T TUStack<T>::Pop()
{
	if(index <0)
		throw NotInBounds(index, size, "you are trying to pop of an empty array");
	index--;
	return stack[index];
}
template <class T>
T& TUStack<T>::operator[ ] (int index)
{
	if(index < 0 )
		throw NotInBounds(index, size, "the indicated index is negative"); 
	else if (index >= size)
		throw NotInBounds(index, size, "the indicated index is larger than the size of the array"); 
	else return stack[index];

};


#endif
//how many classe you decide (minimum number so if you can do one use one)
//pop from empty stack
//if stack is full throw exception
//if you try to push the same value on the stack
//[]operator if beyond an index throw an exception
//three data member
//overloading assignment operator
//copy constructor
//destructor
