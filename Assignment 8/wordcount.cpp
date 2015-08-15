//wordcount.cpp
//Shane Tachick, Will Fisher
//May 2, 2014
//reads a file and gives you the total word count

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <iomanip>
using std::setw;
using std::left;
using std::right;

//Pre-conditions: none
//Post-conditions: Returns each word in the file and how many times it appears, if the file does not exist
//                 or is empty then the user is informed.
int main()
{
	string filename;
	string word;
	map<string, int> words;

	cout << "What is the file name?" << endl;
	getline(cin, filename);

	ifstream getwords(filename);
	while (getwords)
	{
		getwords >> word;
		if (!(getwords))
			break;
		words[word] +=1;
	}

	cout << setw(15) << left << "Word" << setw(5) << right << "Count" << endl;
	cout << "=========================" << endl;
	
	if (words.empty())
	{
		cout << "This file contained no data or did not exist" << endl;
	}
	
	for (auto x : words)
	{
		cout << setw(20) << left << x.first << setw(5) << right << x.second << endl;
	}

	cout << endl;
	cout << "Press enter to exit" << endl;
	while(cin.get() != '\n');

	return 0;
}