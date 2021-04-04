#include "plantType.h"
#include <iostream>
#pragma once


struct Node
{
	plantType data;
	Node * left;
	Node * right;
};

class tree
{
	public:
	
	tree();
	~tree();
	void destroyTree(Node* ptr);
	void createLeaf(int num, char* name);
	void insertLeaf(Node*& root, Node* newNode);
	void traversalPrinting(char* name, int start, int stop);
	void removeNode(int num); // transfer function
	Node* getMinNode(Node* current);
	private:

	Node* removeNodePrivate(int num, Node* parent); // main driver
	void recurseTraversal(char* name, int start, int stp, Node* root);
	Node * root;
	
};
