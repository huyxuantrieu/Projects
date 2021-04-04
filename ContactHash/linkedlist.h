#include <cstring>
#include "person.h"
#pragma once

struct Node
{
	person data;
	Node* next;
};


class linkedlist
{
	public:
	~linkedlist();
	linkedlist();
	const person* getPerson(char* id);	
	void createNode(person per);
	void insert(Node* newNode);
	bool checkHead();
	void initialHead();
	linkedlist(linkedlist&) = delete;
	linkedlist&operator=(linkedlist&)=delete;

	private:
	Node* head;
};
