// da3.cpp (completed)
//Shane Tachick
//February 28, 2013
//calculates the number of steps for the collatz function to reach 1

#include "da3.h"


//Pre-Conditions: 0 < n < largest int size available
//Post-Conditions: Returns number of steps required by the collatz function to reach 1. 
int collatz(int n)
{
	while(n != 1)
	{
		if(n%2 == 0)
			return 1+collatz(n/2);
		else
			return 1+collatz(3*n+1);
	}
	return 0;
}