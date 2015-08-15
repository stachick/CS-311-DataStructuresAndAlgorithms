//birthday.cpp
//Shane Tachick
//February 6, 2014
//function defenitions for birthday.h

#include "birthday.h"
#include <sstream>
using std::ostringstream;

//Preconditions: Name - none. Date - Must be a Valid Calendar date
Birthday::Birthday(string name, int month, int day)
:_name(name), _month(month), _day(day)
{}

//Preconditions: None
string Birthday::monthToString() const
{
	switch (_month){
		case 1: return "Jan";
		case 2: return "Feb";
		case 3: return "Mar";
		case 4: return "Apr";
		case 5: return "May";
		case 6: return "Jun";
		case 7: return "Jul";
		case 8: return "Aug";
		case 9: return "Sep";
		case 10: return "Oct";
		case 11: return "Nov";
		case 12: return "Dec";
		default: return "Jan";

	}
}

//Preconditions: None
string Birthday::toString() const
{
	ostringstream output;
	output << getName() << " (" << monthToString() << " " << getDay() << ")";
	return output.str();
}

//Preconditions: None
//Postconditions: Day has been set to the passed day.
void Birthday::setDay(int newDay)
{
	_day = newDay;
}

//Preconditions: None
//Postconditions: Month has been set to the passed month
void Birthday::setMonth(int newMonth)
{
	_month = newMonth;
}

//Preconditions: None
//Postconditions: Name has been set to the passed string
void Birthday::setName(string newName)
{
	_name = newName;
}

//Preconditions: None
int Birthday::getDay() const
{
	return _day;
}

//Preconditions: None
int Birthday::getMonth() const
{
	return _month;
}

//Preconditions: None
string Birthday::getName() const
{
	return _name;
}

//Preconditions: None
//Postconditions: toPrint has been printed to os in the format: Name (month day) 
ostream & operator<<(ostream & os, const Birthday & toPrint)
{
	return os << toPrint.toString();
}

//Preconditions: None
bool operator==(const Birthday & lhs, const Birthday & rhs)
{
	return ((lhs._name == rhs._name)&&(lhs._month == rhs._month)&&(lhs._day && rhs._day));
}

//Preconditions: None
bool operator!=(const Birthday & lhs, const Birthday & rhs)		//canonical
{
	return !(lhs == rhs);
}

