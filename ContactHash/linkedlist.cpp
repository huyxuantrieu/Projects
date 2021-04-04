#include "linkedlist.h"
#include "person.h"

linkedlist::linkedlist()
{
	head = nullptr;
}
void linkedlist::createNode(person per)
{
	Node* newNode = new Node;
	newNode->data = per;
	newNode->next = nullptr;	
	insert(newNode);	
}

linkedlist::~linkedlist()
{
	if(!head)
	{
		return;	
	}
	
	Node *current = head;
	while(head)
	{	
		current = head;
		head = head->next;
		delete current;
	}

}

const person* linkedlist::getPerson(char* id)
{
	Node* current = head;	
	while(current)
	{
	
		if(strcmp(current->data.getID(), id)== 0 )
		{
			return &current->data;	
		}
		current = current->next;
	}
	return nullptr;			
}

void linkedlist::insert(Node* newNode)
{	
	if(!head)
	{
		head = newNode;
	}	
	else
	{
		Node* current = head;
		while(current)
		{
			if(current->next == nullptr)
			{
				current->next = newNode;
				return;
			}
			else
			{
				current = current->next;
			}
		}
	}

}

bool linkedlist::checkHead()
{
	bool flag = false;
	if(head)
	{
		flag = true;
	}
	
	return flag;
}
