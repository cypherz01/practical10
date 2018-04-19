//================================================================================
// Name        : practical10.cpp
// Author      :
// Version     : 1.0
// Description : practical 10 test program to utilise HashTable class
//================================================================================

#include <iostream>
#include <string>
#include "HashTableOpen.h"

// for optional question comment out previous include and uncomment this include
//#include "HashTableChaining.h"

using namespace std;


void testHash() {

	// create a table of size 5
	HashTable<string> table(5);


	// add 4 entries so table is full -not good practice!
	table.add("noah", "NoahI@gmail.com");
	table.add("Tom", "TomC@gmail.com");
	table.add("dylan", "DylanR@gmail.com");
	table.add("Charlie", "CharlieC@gmail.com");
	table.add("aidy", "aiden@gmail.com");



	// print the table
	cout << "table\n" << table << endl;

	// create a sentinel controlled loop to repeatedly prompt for a key, search table and
	// print result if found or not found, until sentinel key 'quit' is entered
	string key = "";
	string value = "";
	do {
		cout << "please insert key or type quit to leave: " << endl;
		cin >> key;
		if (table.find(key, value) == true)
		{
			cout << "Found: " << value << endl;
		}
		else
		{	
			cout << "not found" << endl;
		}
	}
		while (key != "quit");
	
}
	


// Main method.
int main()
{
    testHash();

    // ---------------------------------------------------
    std::cout << std::endl << "Press enter to quit";
    std::cin.sync(); // flush input buffer
    std::cin.ignore(); // ignore what user enters

    return 0;
}