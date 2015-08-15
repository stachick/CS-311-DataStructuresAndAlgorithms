// Shane Tachick, Andrew Howard
// 2014-04-11
// slstack.h
// Header file for SLStack class -- A wrapper for the SList class.

#ifndef SLSTACK_H
#define SLSTACK_H

#include "slist.h"

template <typename T>
class SLStack
{
public:

	typedef T value_type;
	typedef size_t size_type;
	typedef value_type * iter;
	typedef const value_type * const_iter;

	explicit SLStack();
	SLStack(const SLStack & copyStack);
	SLStack& operator= (SLStack rhs);
	~SLStack();
	void push(value_type toPush);
	void pop();
	bool empty();
	bool empty() const;
	value_type & top(value_type var);
	const value_type & top() const;

private:
	SList<value_type> stack;
};

// Default ctor
// Pre: None
// Post: A new SLStack of the given type is created.
// No-throw guarantee -- a new default SList is created, which should not allocate any memory yet.
// Template types: can use any data type.
template <typename T>
SLStack<T>::SLStack()
{
}

// Copy ctor
// Pre: There must be enough memory to create a new stack.
// Post: A copy of the given stack is created.
// Strong guarantee: may throw bad_alloc.
// Template types: can use any data type.
template <typename T>
SLStack<T>::SLStack(const SLStack & copyStack)
{
	stack = copyStack.stack;
}

// Copy assignment
// Pre: There must be enough memory to create a new stack.
// Post: A copy of the other stack is made.
// Strong guarantee: may throw bad_alloc.
// Template types: can use any data type.
template <typename T>
SLStack<T>& SLStack<T>::operator= (SLStack rhs)
{
	/*
	SList<value_type> tempStack = stack;
	try
	{
		tempStack = rhs.stack;
	}
	catch (...)
	{
		throw;
	}
*/
	return *this;
}

// Dctor
// Pre: None
// Post: The current SLStack is destroyed.
// No-throw guarantee -- does not throw any exceptions.
template <typename T>
SLStack<T>::~SLStack()
{
}

// Push
// Pre: The value type must fit with the current stack.
// Post: The item is placed on the top of the stack.
// Stong guarantee: addFront may throw bad_alloc.
template <typename T>
void SLStack<T>::push(value_type toPush)
{
	stack.addFront(toPush);
}

// Pop
// Pre: None
// Post: The top item of the stack is removed.
// No-throw guarantee: does not throw any exceptions.
template <typename T>
void SLStack<T>::pop()
{
	//if(stack._head == nullptr)
	//return;
	stack.removeFront();
}

// Empty
// Pre: none
// Post: Returns true if the stack is empty (i.e. size of internal SList is 0), false otherwise
// No-throw guarantee: does not throw any exceptions.
template <typename T>
bool SLStack<T>::empty()
{
	return stack.size() == 0;
}

// Empty (const)
// Pre: none
// Post: Returns true if the stack is empty (i.e. size of internal SList is 0), false otherwise
// No-throw guarantee: does not throw any exceptions.
template <typename T>
bool SLStack<T>::empty() const
{
	return stack.size() == 0;
}

// Top
// Pre: Stack must not be empty.
// Post: Returns a reference to the top item of the stack.
// No-throw guarantee: does not throw any exceptions.
template <typename T>
typename SLStack<T>::value_type & SLStack<T>::top(value_type var)
{
	if (stack._head != nullptr)
		stack._data = var;
	return stack._head->_data;

}

// Top (const)
// Pre: Stack must not be empty.
// Post: Returns a reference to the top item of the stack.
// No-throw guarantee: does not throw any exceptions.
template <typename T>
const typename SLStack<T>::value_type & SLStack<T>::top() const
{
		return stack._head->_data;
}

#endif	 //ifndef SLSTACK_H