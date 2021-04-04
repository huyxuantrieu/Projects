#include "datalogger.h"
#include "linkedlist.h"
using namespace std;

void datalogger::addData(int sec, int exp, int spd)
{
	list.insert(sec, exp, spd);	

}

void datalogger::removeSector(int sec)
{
	while (list.containSector(sec))
	{
		list.removeSector(sec);
	}
}

void datalogger::printSectorList()
{
	list.printSectorList();
}

void datalogger::printReport()
{
	list.printList();
}

bool datalogger::containsSector(int sec)
{
	bool contain;

	contain = list.containSector(sec);
	return contain;

}

