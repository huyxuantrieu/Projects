#include "hashtable.h"
#include "person.h"
#include <cstring>
#pragma once



class personmgr
{
	public:
	void addPerson(person per);
	const person* findPerson(char* key); //  const;
	void printHtStats();	

	private:
	hashtable table;
};
