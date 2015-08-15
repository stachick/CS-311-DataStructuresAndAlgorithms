//counthsw.h
//Shane Tachick
//March 22, 2014
//Assignment 4

#ifndef COUNTHSW_H
#define COUNTHSW_H
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

//Workhorse function for countHSW
//Preconditions: The board is properly configured with a 'border' of forbidden squares
//Postconditions: total >= 0
int countHSW_recurse(vector<int> &spiderBoard, int size_x, int size_y, int finish_x, int finish_y, int position_x, int position_y, int remainingSquares)
{
	if (remainingSquares == 0 && position_x == finish_x && position_y == finish_y)
		return 1;
	int total = 0;

	//step right
	if ((spiderBoard[(position_x +(position_y*(size_x))) +1]) == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x)))+1] = 1;
		position_x ++;
		remainingSquares --;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		position_x --;
		remainingSquares++;
		spiderBoard[(position_x +(position_y*(size_x)))+1] = 0;
	}
	//step left
	if ((spiderBoard[(position_x +(position_y*(size_x))) -1]) == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x)))-1] = 1;
		position_x --;
		remainingSquares --;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		position_x ++;
		remainingSquares++;
		spiderBoard[(position_x +(position_y*(size_x)))-1] = 0;
	}
	//step up
	if(spiderBoard[(position_x +(position_y*(size_x))) + size_x] == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x))) + size_x] = 1;
		position_y++;
		remainingSquares--;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		position_y--;
		remainingSquares++;
		spiderBoard[(position_x +(position_y*(size_x))) + size_x] = 0;
	}
	//step down
	if(spiderBoard[(position_x +(position_y*(size_x))) - size_x] == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x))) - size_x] = 1;
		position_y--;
		remainingSquares--;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		position_y++;
		remainingSquares++;
		spiderBoard[(position_x +(position_y*(size_x))) - size_x] = 0;
	}
	//step up and right
	if(spiderBoard[(position_x +(position_y*(size_x))) + size_x +1] == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x))) + size_x +1] = 1;
		position_y++;
		position_x++;
		remainingSquares--;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		position_x--;
		position_y--;
		remainingSquares++;
		spiderBoard[(position_x +(position_y*(size_x))) + size_x +1] = 0;
	}
	//step up and left
	if(spiderBoard[(position_x +(position_y*(size_x))) + size_x -1] == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x))) + size_x -1] = 1;
		position_y++;
		position_x--;
		remainingSquares--;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		remainingSquares++;
		position_y--;
		position_x++;
		spiderBoard[(position_x +(position_y*(size_x))) + size_x -1] = 0;
	}
	//step down and right
	if(spiderBoard[(position_x +(position_y*(size_x))) - size_x +1] == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x))) - size_x +1] = 1;
		position_x++;
		position_y--;
		remainingSquares--;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		remainingSquares++;
		position_x--;
		position_y++;
		spiderBoard[(position_x +(position_y*(size_x))) - size_x +1] = 0;
	}
	//step down and left
	if(spiderBoard[(position_x +(position_y*(size_x))) - size_x -1] == 0)
	{
		spiderBoard[(position_x +(position_y*(size_x))) - size_x -1] = 1;
		position_y--;
		position_x--;
		remainingSquares--;
		total += countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, position_x, position_y, remainingSquares);
		remainingSquares++;
		position_y++;
		position_x++;
		spiderBoard[(position_x +(position_y*(size_x))) - size_x -1] = 0;
	}
	return total;
}

/*
countHSW returns an integer value for the number of solutions. 
Precontidions:	0 <= forbid_x <= size_x
				0 <= forbid_y <= size_y
				0 <= start_x <= size_x
				0 <= start_y <= size_y
				forbid_x != start_x
				forbid_y != start_y
Postconditions: returns an integer representing the number of solutions
*/
int countHSW(int size_x, int size_y, int forbid_x, int forbid_y, int start_x, int start_y, int finish_x, int finish_y)
{
	//these operations adjust the coordinates to work with how I handled the board
	size_x += 2;
	size_y += 2;
	finish_x ++;
	finish_y ++;
	forbid_x ++;
	forbid_y ++;
	start_x ++;
	start_y ++;

	int boardsize = (size_x)*(size_y);
	int remainingSquares = (size_x-2)*(size_y-2)-2;
	vector<int> spiderBoard(boardsize);
	//the following sets up a 1D vector to act as a 2D board that is surrounded by a border of forbidden squares
	for(int i = 0; i < boardsize; ++i)
	{
		if (i < size_x)
			spiderBoard[i] = 1;
		else if ((i%(size_x)) == 0)
			spiderBoard[i] = 1;
		else if ((i%(size_x)) == (size_x-1))
			spiderBoard[i] = 1;
		else if (i > ((size_x)*(size_y-1)))
			spiderBoard[i] = 1;
		else
			spiderBoard[i]=0;
	}
	spiderBoard[forbid_x + (forbid_y*(size_x))] = 9;
	spiderBoard[start_x + (start_y*(size_x))] = 2;
	spiderBoard[finish_x + (finish_y*(size_x))] = 0;

	return countHSW_recurse(spiderBoard, size_x, size_y, finish_x, finish_y, start_x, start_y, remainingSquares);
}




#endif //COUNTHSW_H