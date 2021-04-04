#include "hashtable.h"
#include "linkedlist.h"
#include "person.h"


hashtable::hashtable()
{
	list = new linkedlist [arraySize];	
}

hashtable::~hashtable()
{
	if(list)
	{

		delete [] list;
	}
}

void hashtable::insert(person per)
{
	
	int index = hashFunction(per.getID());
	
	list[index].createNode(per);	
}

int hashtable::hashFunction(char* id)
{
	int index;
	int total = 0;

	int size = strlen(id);
	
	for(int i = 0; i < size; i++)
	{
			
		total = total + (int)id[i];
	}

	if(size > 2)
	{
		total = total * (int)id[size-1];
	}
	
	if(size >3 )
	{
		total = total *(int)id[size-2];// this made the hash more effiicent in runtime.  
	}
	
	index = total % arraySize;
	return index;

}

const person* hashtable::lookup(char* id)
{
	int index = hashFunction(id);	
		
	const person* personObj = list[index].getPerson(id);
	if(personObj == nullptr)
	{
		std::cout << "cant find id" << std::endl;
	}	
	return personObj;	
}

int hashtable::checkEmpty()
{
	int headCounter = 0;
	for(int i=0; i>arraySize; i++)
	{
		if(list[i].checkHead() == true)
		{
			headCounter++;
		}		
	}

	//returns number of head pointers that were not used, and were nullptr.
	return headCounter;	
}



