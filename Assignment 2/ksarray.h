// ksarray_test.h
// Shane Tachick
// 2/17/2014
//header file for class KSarray

#ifndef KSARRAY_H
#define KSARRAY_H

#include <algorithm>
using std::copy;
#include <cstdlib>
using std::size_t;

//Class Invariants
//size >= 0

template <class arrayType>
class KSArray
{
public:
	typedef arrayType value_type;
	typedef size_t size_type;
	KSArray();
	KSArray(size_type x);				//1 parameter ctor
	KSArray(size_type x, value_type y);	//2 parameter ctor
	KSArray(const KSArray & arr);		//Copy ctor. Deep copy.
	~KSArray();							//dtor
	size_type size() const;				//returns size of the array
	value_type * begin();				//returns address of the first element in the array
	value_type * end();					//returns address of the last element in the array
	const value_type *begin() const;	//begin() for the const array
	const value_type *end() const;		//end() for the const array

	value_type &operator[](size_type index);
	const value_type &operator[](size_type index) const;
	KSArray &operator=(const KSArray &arr);

private:
	size_type _size;	//represents the size of the array
	value_type *_ptr;	//pointer to the first element in the array

};

template <class arrayType>
bool operator==(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs);
template <class arrayType>
bool operator!=(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs);
template <class arrayType>
bool operator<(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs);
template <class arrayType>
bool operator>(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs);
template <class arrayType>
bool operator<=(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs);
template <class arrayType>
bool operator>=(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs);

//Default ctor
//Pre-Conditions: none
//Post-Conditions: creates an array of 10 units of value_type
template<class arrayType>
KSArray<arrayType>::KSArray()
	:_ptr(new value_type [10]), _size(10)
{}

//1 parameter ctor
//Pre-Conditions: size >= 0
//Post-Conditions: creates an array with 'size' elements of 'value-type'
template<class arrayType>
KSArray<arrayType>::KSArray(size_type x)
	:_ptr(new value_type[x]), _size(x)
{}

//2 paramter ctor
//Pre-Conditions: size >= 0. valid object y of value_type
//Post-Conditions: creates an array of value_type with size x and all elements set to y
template<class arrayType>
KSArray<arrayType>::KSArray(size_type x, value_type y)
	:_ptr(new value_type[x]), _size(x)
{
	for(size_t i = 0; i < _size; ++i)
	{
		_ptr [i] = y;
	}
}

//copy ctor
//Pre-Conditions: arr must be a valid object of class arrayType. 
//Post-Conditions: deallocates arr and creates a new object of class valueType that is a copy of arr
template<class arrayType>
KSArray<arrayType>::KSArray(const KSArray & arr)
	:_ptr(new value_type[arr.size()]), _size(arr.size())
{
	for(size_t i = 0; i < arr.size(); ++i)
	{
		_ptr[i] = arr[i];
	}
}

//dtor
//Pre-Conditions: none
//Post-Conditions: memory is deallocated
template<class arrayType>
KSArray<arrayType>::~KSArray()
{
	delete [] _ptr;
}

//Pre-Conditions: none
//Post-Conditions: Returns size of array
template<class arrayType>
typename KSArray<arrayType>::size_type KSArray<arrayType>::size() const
{
	return _size;
}

//Pre-Conditions: none
//Post-Conditions: returns address of the first element in the array
template<class arrayType>
typename KSArray<arrayType>::value_type *KSArray<arrayType>::begin()
{
	return _ptr;
}

//Pre-Conditions: Template is const
//Post-Conditions: returns address of the first element in the array
template<class arrayType>
const typename KSArray<arrayType>::value_type *KSArray<arrayType>::begin() const
{
	return _ptr;
}

//Pre-Conditions: none
//Post-Conditions: returns address of the last element in the array
template<class arrayType>
typename KSArray<arrayType>::value_type *KSArray<arrayType>::end()
{
	return (begin() + _size);
}

//Pre-Conditions: Template is const
//Post-Conditions: returns address of the last element in the array
template<class arrayType>
const typename KSArray<arrayType>::value_type *KSArray<arrayType>::end() const
{
	return (begin() + _size);
}

//Pre-Conditions: index must be a valid index of the array
//Post-Conditions: returns address of passed index
template<class arrayType>
typename KSArray<arrayType>::value_type &KSArray<arrayType>::operator[](typename KSArray::size_type index)
{	
		return (_ptr[index]);
}

//Pre-Conditions: index must be a valid index of the array
//Post-Conditions: returns address of passed index
template<class arrayType>
const typename KSArray<arrayType>::value_type &KSArray<arrayType>::operator[](typename KSArray::size_type index) const
{
		return (_ptr[index]);
}

//Pre-Conditions: Operator != must be defined.
//Post-Conditions: assigns arr to *this
template<class arrayType>
KSArray<arrayType> &KSArray<arrayType>::operator=(const KSArray &arr)
{
	if (this != &arr)
	{
		delete [] _ptr;
		_size = arr.size();
		_ptr = new arrayType[arr.size()];
		for(size_t i = 0; i< arr.size(); ++i)
		{
			_ptr[i] = arr[i];
		}
	}
	return *this;
}

//Pre-Conditions: operator != must be defined
//Post-Conditions: returns true if 2 arrays have equal size and the same elements int he same order, otherwise returns false
template <class arrayType>
bool operator==(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs)
{
	if(lhs.size() != rhs.size())
	{
		return false;
	}
	else
	{
		for (size_t i=0; i < lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
	}
	return true;
}

//Pre-Conditions: operator == must be defined
//Post-Conditions: returns the opposite results of == operation.
template <class arrayType>
bool operator!=(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs)
{
	return !(lhs == rhs);
}

//Pre-Conditions: operator > and == must be defined
//Post-Conditions: returns true if lhs < rhs
template <class arrayType>
bool operator<(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs)
{
	if(lhs ==  rhs)
		return false;
	if(lhs.size() > rhs.size())
		return false;
	for(size_t i = 0; i < lhs.size(); ++i)
	{
		if(lhs[i] > rhs[i])
			return false;
	}
	return true;
}

//Pre-Conditions: operator < and == must be defined
//Post-Conditions: returns true if lhs > rhs
template <class arrayType>
bool operator>(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs)
{
	return (!(lhs < rhs) && !(lhs == rhs));
}

//Pre-Conditions: operator > must be defined
//Post-Conditions: returns true if lhs <= rhs
template <class arrayType>
bool operator<=(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs)
{
	return !(lhs > rhs);
}

//Pre-Conditions: operator < must be defined
//Post-Conditions: returns true if lhs >= rhs
template <class arrayType>
bool operator>=(const KSArray<arrayType> &lhs, const KSArray<arrayType> &rhs)
{
	return !(lhs < rhs);
}

#endif //KSARRAY_H

