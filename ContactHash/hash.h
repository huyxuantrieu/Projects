#include "linkedlist.h"
#include "person.h"
#pragma once


	
class hashtable
{
	public:
	hashtable();
	person lookup(char* ID);
	int hashFunction(person per);
	void insert(person per);
	private:
	linkedlist *list;

};
