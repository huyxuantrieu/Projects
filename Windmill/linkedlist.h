#include "surveyData.h" 
#include <iostream>
using namespace std;
#pragma once

struct Node
{
	surveyData *data;
	Node *nextSector;
	Node *nextExposure;
	Node *nextSpeed;
		
};

class linkedlist
{
	public:
	linkedlist();
	~linkedlist();
	linkedlist(linkedlist &orig);
	linkedlist & operator=(linkedlist &orig);	
	void insert(int sec, int exp, int spd);
	void insertSector(Node *newNode);
	void insertExposure(Node *newNode);
	void insertSpeed(Node *newNode);
	bool containSector(int sec);
	void removeSector(int sec);
	void printList();
	void printOrderSector();
	void printOrderExposure();
	void printOrderSpeed();
	void printAvgPerSector();
	void printHistogramExposure();
	void printHistogramSpeed();
	void printSectorList();
	void copyList(linkedlist &cpy);
	
	private:
	int count = 0;
	Node *headSector;
	Node *headExposure;
	Node *headSpeed;
};


