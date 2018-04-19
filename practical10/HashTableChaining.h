/**
 * HashTable.h
 *
 * Hash Table - Chaining
 *
 * @author  Aiden McCaughey
 * @email   a.mccaughey@ulster.ac.uk#
 * @version 1.0
 */

#ifndef HASH_H_
#define HASH_H_

#include <string>
#include "Array.h"
#include "LinkedList.h"


template <class T>
class HashTable 
{
public:
	HashTable(int size=101) : table(size), currentsize(0) {}
	void clear();
	bool add(std::string k, const T & x);
	bool remove(std::string k);
	bool find(std::string k, T & x) const;
	void print(std::ostream & out) const;
	void rehash(int size);

private:
	struct HashEntry {
	   std::string key;
       T element;

	   HashEntry(const std::string & k = "", const T & e = T()) : key(k), element(e) {}
	   // overloaded equality operator
	   bool operator==(const HashEntry & rhs)	{ return key == rhs.key; }
	};

	int hash(const std::string & k) const;

	// table based on an Array of LinkedLists
	Array< LinkedList<HashEntry> > table;
	int currentsize;

};

// ------------------ HASHTABLECHAINING.CPP ------------------------------------

// PostCondition: private hash function
template <class T>
int HashTable<T>::hash(const std::string & s) const {
	int pos = 0;
	for(unsigned int i=0; i<s.length(); i++)
		pos += s[i];
	return pos % table.length();
}


// PostCondtion: table is emptied
template <class T>
void HashTable<T>::clear() {
	for(int i=0; i<table.length(); i++)
		table[i].clear();	// empty the list
}

// PreCondtion : size > table.length() && isPrime
// PostCondtion: resize the table and rehash active hash entries
template <class T>
void HashTable<T>::rehash(int size) {
	if (size > table.length()) {
		// copy table to a temporary array
		Array< LinkedList<HashEntry> > tmp = table;

		// empty the table
		clear();

		// create a new table
		table = Array< LinkedList<HashEntry> >(size);

		for(int i=0; i<tmp.length(); i++) {
			LinkedList<HashEntry> & list = tmp[i];
			for(ListIterator<HashEntry> itr = list.begin(); itr != list.end(); itr++) {
				add((*itr).key, (*itr).element);
			}
		}
	}
}

// PostCondition: new HashEntry containing key and val is inserted into the table
template <class T>
bool HashTable<T>::add(std::string key, const T & val) {
	
    int pos = hash(key);                                // hash the key
	LinkedList<HashEntry> & list = table[ pos ];	// select correct list
	list.add( HashEntry(key, val) );		            // insert new hash entry
	currentsize++;	                                    // increment table size
	return true;
}


// PreCondition: table is not full
// PostCondition: if located element is deleted from list
template <class T>
bool HashTable<T>::remove(std::string key) {	
    int pos = hash(key);                                // hash the key
	LinkedList<HashEntry> & list = table[ pos ];	    //select correct list
	int i = list.find(HashEntry(key));                  // determine position of HashEntry in list
	if (i != -1) {
		list.remove(i);	// remove item
 	    currentsize--;	// decrement table size
		return true;
    } else {
		return false;
	}
}



// --------------------- IMPLEMENT THESE FUNCTIONS ---------------------

// PostCondition: if element identified by key is found element is 
//                returned in reference parameter val and function
//                returns true, otherwise function returns false
template <class T>
bool HashTable<T>::find(std::string key, T & val) const {

    // implement this function.Hint the remove function above is a good guide
    return false;
}


// PostCondition: table HashEntries are printed to output stream
template <class T>
void HashTable<T>::print(std::ostream & out) const {

    // implement this function
    out << "Not yet implemented\n";

}

// PostCondition: overload << operator to output table on ostream
template <class T>
std::ostream & operator<<(std::ostream& output, const HashTable<T> & t) {
    t.print(output);
    return output;  // for multiple << operators.
}
#endif
