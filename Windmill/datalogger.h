#include "linkedlist.h"
#pragma once


class datalogger
{
	public:
	void addData(int sec, int exp, int spd);
	void removeSector(int sec);
	bool containsSector(int sec);
	void printReport();
	void printSectorList();
	
	private:
	linkedlist list;
	
};
