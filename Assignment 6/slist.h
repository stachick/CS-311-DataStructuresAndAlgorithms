//slist.h
//Shane Tachick
//Andrew Howard
//Header file for Linked List class template

#ifndef SLIST_H
#define SLIST_H


#include<cstdlib>
using std::size_t;
#include<algorithm>
using std::swap;

// these are the actual nodes being added to the list or stack
// Invariants: _next either points at nullptr or another node allocated with new and owned by *this
// Type Requirements: nodeData must be copyable, nodeData dtor must not throw
template <typename nodeData>
struct Node
{
	Node * _next;
	nodeData _data;

	// ctor
	// Pre: nextNode points at nullptr or a Node allocated by new
	// Post: _data == data, _next == nullptr or nextNode, owned by *this
	// Strong Guarantee, Exception Neutral
	explicit Node(const nodeData & data, Node * nextNode = nullptr)
		:_data(data), _next(nextNode)
	{}

	// dtor
	// Pre: None
	// Post: _next deleted
	// No-Throw Guarantee
	~Node()
	{
		delete _next;
	}
};

// this is the class that holds the head that knows where the first node actually is, it also contains all the functions
// Invariants: _head points at nullptr or a Node allocated with new
// Type Requirements: value_type must be copyable; value_type dtor must not throw
template <typename T>
class SList
{
public:
	typedef T value_type;
	typedef std::size_t size_type;
	typedef value_type * iter;
	typedef const value_type * const_iter;

	SList();
	SList(const SList & copyList);
	~SList();
	SList<T>& operator= (SList rhs);
	void reverse();
	const size_type size() const;
	void addFront(value_type data);
	void removeFront();
	void swap(SList list);

	template<typename OutputIterator>
	void write(OutputIterator location) const;
	
	template<typename InputIterator>
	void read(InputIterator begin, InputIterator end);

//private:
	Node<value_type> * _head;
	size_type _size;
};

// default ctor
// Pre: none
// Post: head_ == nullptr; size_ == 0
// No-Throw Guarantee
template <typename T>
SList<T>::SList()
	:_head(nullptr), _size(0)
{}

// copy ctor
// Pre: None
// Post: Both SLists are identical
// Strong Guarantee
template <typename T>
SList<T>::SList(const SList & copyList)
{
	_head = nullptr;
	_size = 0;
	
	
    Node<value_type> * temp = copyList._head;

    while(temp != nullptr)
    {
        addFront(temp->_data);
        temp = temp->_next;
    }
	
}

// dctor
// Pre: none
// Post: _head deleted
// No-Throw Guarantee
template <typename T>
SList<T>::~SList()
{
	delete _head;
}

// copy =
// Pre: None
// Post: None
// Strong Guarantee
template <typename T>
SList<T>& SList<T>::operator= (SList rhs)
{
	swap(rhs);
	return *this;
}

// reverse function
// Pre: none
// Post: the list is now in reverse order
// No-Throw Guarantee
template <typename T>
void SList<T>::reverse()
{
	Node<value_type> * tempSave = nullptr;
	while (_head != nullptr)
	{
		Node<value_type> * temp = _head;
		_head = _head->_next;
		temp->_next = tempSave;
		tempSave = temp;
	}
	_head = tempSave;
}

// size function
// Pre: none
// Post: returns _size
// No-Throw Guarantee
template <typename T>
const typename SList<T>::size_type SList<T>::size() const
{
	return _size;
}

// addFront function
// Pre: none
// Post: item has been added to a new node at the front of the list
// Strong Guarantee - Exception neutral
template <typename T>
void SList<T>::addFront(value_type data)
{
	_head = new Node<value_type>(data, _head);
	++_size;
}

//	swap function
//	Pre Conditions: None
//	Post Condition: Values deeply copied as part of swapping values between the lists.
//	Strong Guarantee
template <typename T>
void SList<T>::swap(SList list)
{
	std::swap(list._head, _head);
	std::swap(list._size, _size);
}

// removeFront function
// Pre: none
// Post: the first item in the list is destroyed; does nothing on an empty list
// No-Throw Guarantee
template <typename T>
void SList<T>::removeFront()
{
	if (_head == nullptr)
		return;
	Node<value_type> * temp = _head->_next;
	_head->_next = nullptr;
	delete _head;
	_head = temp;
	--_size;
}

// write function
// Pre: location is a valid iterator
// Post: none
// Basic Guarantee
template <typename T>
template<typename OutputIterator>
void SList<T>::write(OutputIterator location) const
{

	Node<value_type> * copyHead = _head;
	while(copyHead != nullptr)
	{
		value_type val = copyHead->_data;
		copyHead = copyHead->_next;
		*location++=val;
	}
}

// read function
// Pre: begin and end should represent a valid list.
// Post: List contains the elements of the list represented by begin and end.
// Basic Guarantee
template <typename T>
template<typename InputIterator>
void SList<T>::read(InputIterator begin, InputIterator end)
{
	SList t;

	while (begin != end)
	{
		value_type val = *begin++;
		t.addFront(val);
	}
	swap(t);
}

#endif		//ifndef SLIST_H