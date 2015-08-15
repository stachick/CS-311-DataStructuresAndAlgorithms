// tsmarray.h
// Shane Tachick, Amanda Harper, Sam George
// April 2, 2014
// Data Structures and algorithms assignment 5

#ifndef TSMARRAY_H
#define TSMARRAY_H
#define _SCL_SECURE_NO_WARNINGS


#include<cstdlib>		//std::size_t
#include<algorithm>		//std::copy
using std::copy;


// Class Invariants
// _capacity >= _size _= 0
// _data is a pointer to an array allocated by new, owned by *this, holding _capacity value_types.
// if default constructed _data is a nullpointer until reassigned
template<class T>
class TSmArray
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type * iterator;
	typedef const value_type * const_iterator;

	TSmArray() :	_size(0), 
					_capacity(0), 
					_data(nullptr){}							// default constructor
	TSmArray( const TSmArray & arr);							// copy constructor
	TSmArray( size_type size );									// 1-param constructor
	TSmArray &operator= ( TSmArray rhs );						// copy assignment
	~TSmArray();												// destructor
	iterator insert( iterator iter, const value_type & value );	// insert
	iterator remove( iterator iter);							// remove
	void swap(TSmArray<T> &rhs);								// swap
	const_iterator end() const;									// const end
	iterator end();												// end
	const_iterator begin() const;								// const begin
	iterator begin();											// begin
	const value_type & operator[](size_type index) const;		// const operator []
	value_type & operator[](size_type index);					// operator []
	size_type size() const;										// size
	bool empty() const;											// empty
	void resize(size_type newSize);								// resize


private:
	size_type _size;
	size_type _capacity;
	value_type *_data;
};

//1-param constructor//
// exception neutral//
// strong guarentee
//pre-conditions: size > 0;
//	  operator [] defined
//post-conditions: size memory allocated for a new TSmArray
template<class T>
TSmArray<T>::TSmArray(size_type size)
:_size(size), _capacity(_size), _data(new value_type[_capacity])
{}


//copy constructor//
// exception neutral
// strong guarentee
//pre-conditions: none
//post-conditions: memory alloted for a new TSmArray object which is equivalent to a passed TSmArray object
template<class T>
TSmArray<T>::TSmArray(const TSmArray &rhs)
	:_size(rhs._size), _capacity(_size), _data(new value_type [_capacity])
{
	try
	{
		copy(rhs.begin(), rhs.end(), _data);
	}
	catch(...)
	{
		delete[] _data;
		throw;
	}
}

// copy assignment //
// exception neutral //
// strong guarentee //
// pre-conditions: none
// post-conditions: swaps all values of the left object with rhs
template<class T>
TSmArray<T>& TSmArray<T>::operator= ( TSmArray<T> rhs)
{
	swap(rhs);
	return *this;
}

// destructor //
// no throw guarentee
// pre-conditions: none //
// post-conditions: freed memory //
template<class T>
TSmArray<T>::~TSmArray()
{
	delete[] _data;
}

// remove //
// strong gurantee
// pre-conditions: being() <= target < end()
// post-conditions: data in memory starting at target is moved forward to replace the value at target
//	 _size is then reduced by one
template<class T>
typename TSmArray<T>::iterator TSmArray<T>::remove( iterator target )
{
	size_type index = target - begin();
	for (unsigned int i = index; i != _size - 1; i++)
	{
		_data[i] = _data[i + 1];
	}
	resize(_size - 1);
	return target;
}


// insert //
// strong gurantee
// pre-conditions: begin() <= iter < end()
// post-conditions: value is placed in memory at iter,
//	 following data after value is pushed back in order and _size is increased
//	 returns iterator to the inserted  value
template<class T>
typename TSmArray<T>::iterator TSmArray<T>::insert(iterator iter, const value_type & value)
{
	size_type index = iter - begin();
	resize(_size + 1);
	iter = index + begin();
	for (unsigned int i = _size - 1; i != index; i--)
	{
		_data[i] = _data[i - 1];
	}
	_data[index] = value;
	return iter;
}

//Pre: 0 <= index < _size
//Post: return value: _data[index]
//Does not throw
template <class T>
typename TSmArray<T>::value_type & TSmArray<T>::operator[](size_type index)
{
	return (_data[index]);
}

//Pre: 0 <= index < _size
//Post: return value: _data[index]
//Does not throw
template <class T>
typename const TSmArray<T>::value_type & TSmArray<T>::operator[](size_type index) const
{
	return (_data[index]);
}

//Pre: none
//Post: return value: pointer to first object stored in *this
//Does not throw
template <class T>
typename TSmArray<T>::iterator TSmArray<T>::begin()
{
	return _data;
}

//Pre: none
//Post: return value: pointer to first object stored in *this
//Does not throw
template <class T>
typename TSmArray<T>::const_iterator TSmArray<T>::begin() const
{
	return _data;
}

//Pre: none
//Post: return value: pointer to just-past last object in *this
//Does not throw
template <class T>
typename TSmArray<T>::iterator TSmArray<T>::end()
{
	return (_data + _size);
}

//Pre: none
//Post: return value: pointer to just-past last object in *this
//Does not throw
template <class T>
typename TSmArray<T>::const_iterator TSmArray<T>::end() const
{
	return (_data + _size);
}

//Pre: none
//Post: parameter array and *this have swapped _data, _capacity and _size
//Does not throw
template <class T>
void TSmArray<T>::swap(TSmArray<T> &rhs)
{
	std::swap(rhs._size, _size);
	std::swap(rhs._capacity, _capacity);
	std::swap(rhs._data, _data);
}

//Pre: none
//Post: returns _size of *this
//No Throw Guarantee 
template <class T>
typename TSmArray<T>::size_type TSmArray<T>::size() const
{
	return _size;
}

//Pre: none
//Post: returns true if array is empty, false if it is not empty (based on the value of _size)
//No Throw Guarantee 
template <class T>
bool TSmArray<T>::empty() const
{
	return (_size == 0);
}
	
//Pre: _size >= 0
//		newSize > 0
//Post: changes _size to newSize, or changes capacity to 2*newSize and changes _size to newSize
//Strong Guarantee
template <class T>
void TSmArray<T>::resize(size_type newSize)
{
	if(newSize <= _capacity)
	{
		_size = newSize;
	}
	else
	{
		TSmArray<T> temp(2*newSize);
		for (auto i=0; i<_size; i++)
		{
			temp._data[i] = _data[i];
		}
		temp._size = newSize;
		swap(temp);
	}
}

#endif

