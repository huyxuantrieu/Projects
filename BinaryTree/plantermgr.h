#include "tree.h"
#include <iostream>
#pragma once
class plantermgr
{
	public:
	void plant(int num, char* name);
	void harvest(char* name, int start, int stop);
	void prune(int num);
	private: 	
	tree BST;
};
