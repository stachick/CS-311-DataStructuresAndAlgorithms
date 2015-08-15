//birthday.h
//Shane Tachick
//February 6, 2014
//header file for class birthday

#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include<string>
using std::string;
#include <iostream>
using std::ostream;


//Class invariants
//0 < days <= 31, 0 < months <= 12
class Birthday
{
	friend bool operator==(const Birthday & lhs, const Birthday & rhs);

public:
	Birthday(string _name="", int _month=1, int _day=1);
	//using silently written copy ctor, copy assignment, and dtor

	int getDay() const;
	int getMonth() const;
	string getName() const;
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setName(string newName);
	string toString() const;
	string monthToString() const;
	
private:
	string _name;
	int _month;
	int _day;
	
};

ostream & operator<<(ostream & os, const Birthday & toPrint);
bool operator==(const Birthday & lhs, const Birthday & rhs);
bool operator!=(const Birthday & lhs, const Birthday & rhs);

#endif //BIRTHDAY_H