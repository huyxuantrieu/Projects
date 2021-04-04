#include "plantermgr.h"
#include <iostream>


void plantermgr::plant(int num, char* name)
{ 
	BST.createLeaf(num, name);	
	std::cout << "Planting " << name << " in box " << num << std::endl;	
}

void plantermgr::harvest(char* name, int start, int stop)
{ 
	std::cout << "Harvesting " << name << " from boxes " << start << " to " << stop <<". The following boxes will be harvested: ";
	BST.traversalPrinting(name, start, stop);	
	std::cout << std::endl << "\n";
}

void plantermgr::prune(int num)
{
	std::cout << "Pruning box number " << num << "." << std::endl;
	BST.removeNode(num);
}

