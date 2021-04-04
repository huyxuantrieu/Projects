#include "linkedlist.h"
#include "person.h"
#pragma once
const int arraySize = 9973;

	
class hashtable
{
	public:
	~hashtable();
	hashtable();
	const person* lookup(char* ID);
	int hashFunction(char* input);
	void insert(person per);
	int checkEmpty();
	hashtable& operator=(hashtable&) = delete;
	hashtable(hashtable&) = delete;

	private:
	linkedlist *list;

};
