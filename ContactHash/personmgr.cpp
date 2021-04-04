#include "personmgr.h"
#include "person.h"
#include "hashtable.h"
#include "iostream"


void personmgr::addPerson(person per)
{
	table.insert(per);
}
const person*  personmgr::findPerson(char* id) // const
{
	const person* personObject;
	personObject = table.lookup(id);
	return  personObject;
}

void personmgr::printHtStats()
{
	int headPtrUsed;
	headPtrUsed = table.checkEmpty();
	headPtrUsed = arraySize - headPtrUsed;	
	std::cout << "Table has " << headPtrUsed << " out of " << arraySize << " entries." <<  std::endl;	
}

