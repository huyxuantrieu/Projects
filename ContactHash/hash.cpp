#include "hash.h"
#include "linkedlist.h"
#include "person.h"



hashtable::hashtable()
{
	list = new linkedlist [9973];	
}
void hashtable::insert(person per)
{
	int index = hashFunction(per);
	list[index].insert(per);	
}

int hashtable::hashFunction(person per)
{
	int index;
	int total = 0;

	int size = strlen(per.getID());
	char* newID = new char[size+1];
	strcpy(newID, per.getID();

	int convertNum[size+1]
	for(int i = 0; i < size; i++)
	
	{
		convertNum[i] = (int) newID[i];
		total = total + convertNum[i];
	}
	
	index = total % 9973;
	
	return index;
	
}
