// da3.h (finished)
//Shane Tachick
//February 28, 2014
//assignment 3


#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include <iostream>   // for std::ostream
#include <string>     // for std::string


// *************************************************************** // *
// Begin DO-NOT-CHANGE section                                     // *
// Do not alter the lines below                                    // *
// *************************************************************** // *
                                                                   // *
                                                                   // *
// struct LLNode                                                   // *
// Linked List node, with client-specified value type              // *
// Invariants:                                                     // *
//     Either next_ is NULL, or next_ points to an LLNode,         // *
//      allocated with new, owned by *this.                        // *
template <typename ValueType>                                      // *
struct LLNode {                                                    // *
    ValueType data_;  // Data for this node                        // *
    LLNode * next_;   // Ptr to next node, or NULL if none         // *
                                                                   // *
    // The following simplify creation & destruction               // *
                                                                   // *
    // 1- & 2-param ctor                                           // *
    // Pre:                                                        // *
    //     theNext, if passed, is either NULL,                     // *
    //      or else it points to an LLNode, allocated with new,    // *
    //      with ownership transferred to *this.                   // *
    // Post:                                                       // *
    //     data_ == theData.                                       // *
    //     If next_ passed, then next_ == theNext.                 // *
    //      otherwise, next_ is NULL.                              // *
    explicit LLNode(const ValueType & theData,                     // *
                    LLNode * theNext = NULL)                       // *
        :data_(theData), next_(theNext)                            // *
    {}                                                             // *
                                                                   // *
    // dctor                                                       // *
    // Pre: None.                                                  // *
    // Post: None. (next_ delete'd)                                // *
    ~LLNode()                                                      // *
    { delete next_; }                                              // *
};                                                                 // *
                                                                   // *
                                                                   // *
// *************************************************************** // *
// End DO-NOT-CHANGE section                                       // *
// Do not alter the lines above                                    // *
// *************************************************************** // *

//Pre-Conditions: none
//Post-Conditions:	Returns the element that is stored at the index value of the linked list for valid values
//					or throws an out_of_range error if the index passed is not within the range of the linked list 
template <typename T>
T listItem(const LLNode<T> * head,
           int index)
{
	int x = 0;
	bool findMe = false;
	while(head != NULL)
	{
		if (x == index)
		{
			findMe = true;
			return (head-> data_);
		}
		else
		{
			x++;
			head = head-> next_;
		}
	}
	if (!findMe)
	{
		throw std::out_of_range("Out of range error, T listItem");
	}
    return 0; //dummy return statement to avoid warnings. Will never be encountered.
}

//Pre-Conditions: Operator () must be defined for Func
//Post-Conditions: Returns true if F() threw any errors
template <typename Func>
void didItThrow(Func f,
                bool & threw)
{
	try
	{
		f();
		threw = false;
	}
	catch (...)
	{
		threw = true;
		throw;
	}
}

//Pre-Conditions: none
//Post-Conditions: Prints the content between first and last to theStream
template <typename FDIter>
void printRange(FDIter first,
                FDIter last,
                std::ostream & theStream)
{
    for(auto i = first; i != last; i++)
	{
		theStream << *i << std::endl;
	}
}

//Pre-Conditions: none
//Post-Conditions: returns whether two ranges are equal (true) or not (false)
template <typename FDIter>
bool rangesEqual(FDIter first1,
                 FDIter last1,
                 FDIter first2)
{
   return std::equal(first1, last1, first2);
}

//Defined in da3.cpp
int collatz(int n);

#endif  //#ifndef FILE_DA3_H_INCLUDED

