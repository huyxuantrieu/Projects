#include "surveyData.h" 
#include "linkedlist.h"
#include <iostream>
using namespace std;

linkedlist::linkedlist() 
{ 
	headSector = nullptr;
	headExposure = nullptr;
	headSpeed = nullptr;
}

linkedlist::~linkedlist()
{
	Node *current = nullptr;
	while(headSector)
	{
		current = headSector;
		headSector = current->nextSector;
		delete current->data;
		delete current;
	}
}

linkedlist::linkedlist (linkedlist &orig)
{
	this->headSector = nullptr;
	this->headExposure = nullptr;
	this->headSpeed = nullptr;
	this->copyList(orig);
}

linkedlist & linkedlist::operator=(linkedlist &orig)
{
	if(this != &orig)
	{
		if(this->headSector != nullptr)
		{
			Node *current = nullptr;
			while(headSector)
			{
				current = headSector;
				headSector = current->nextSector;
				delete current->data;
				delete current;
			}
			headSector = nullptr;
			headExposure = nullptr;
			headSpeed = nullptr;
		}
		this->copyList(orig);
	}
	return *this;
}

void linkedlist::copyList(linkedlist &orig)
{
	Node * current = orig.headSector;
	while(current)
	{
		int sector;
		int exposure;
		int speed;
		
		sector = current->data->getSector();
		exposure = current->data->getExposure();
		speed = current->data->getSpeed();
		
		insert(sector, exposure, speed);
		current = current->nextSector;
	}
}

//function will insert Sector, Exposure, and Speed in order by calling other insert functions. 
void linkedlist::insert(int sec, int exp, int spd)
{
	surveyData * newData = new surveyData(sec, exp, spd);
	Node *newNode = new Node;

        newNode->nextSector = nullptr;
        newNode->nextExposure = nullptr;
        newNode->nextSpeed = nullptr;
	
        newNode->data = newData;
	
	insertSector(newNode);
	insertExposure(newNode);
	insertSpeed(newNode);
}


void linkedlist::insertSector(Node *newNode)
{
        if (!headSector)
        {
                headSector = newNode;
        }
        else
	{
       		Node * current = headSector;
     		Node * previous = nullptr;
	
		while(current)
       		{
               		if(current->data->getSector() >= newNode->data->getSector())
               		{
                       		newNode->nextSector = current;
                      		if(previous)
                       		{
                               		previous->nextSector = newNode;
					count++;
                       		}
                       		if(!previous)
                       		{
                               		headSector=newNode;	
					count++;
                       		}
				return;
			}
			previous = current; //sets temp variable for inserting
			current = current->nextSector; //sets current to next current for traversing
		}
	        previous->nextSector = newNode; //previous->next would be the last position in list.
	}		
	count++;
}

void linkedlist::insertExposure(Node *newNode)
{
	if (!headExposure)
	{
		headExposure = newNode; 
	}
	else
	{	
		Node * current = headExposure;
		Node * previous = nullptr;
	
		while(current)
		{
			if(current->data->getExposure() >= newNode->data->getExposure())
			{
				newNode->nextExposure = current;
				if(previous)
				{
					previous->nextExposure = newNode;
				}	
				if(!previous)
				{
					headExposure = newNode;
				}
		
				return;
			}
			previous = current; //sets temp variable for inserting
			current = current->nextExposure; //sets current to next current for traversing
		}
		previous->nextExposure = newNode; //previous->next would be the last position in list. 
	}
}


//inserting Speed in order.
void linkedlist::insertSpeed(Node *newNode)
{
        if (!headSpeed)
        {
                headSpeed = newNode;
        }
   	else
	{
	        Node * current = headSpeed;
       		Node * previous = nullptr;

      		while(current)
       		{
	                if(current->data->getSpeed() >= newNode->data->getSpeed())
        	        {
                	        newNode->nextSpeed = current;
                     		if(previous)
                       		{
                	                previous->nextSpeed = newNode;
				}
                       		if(!previous)
                       		{
                               		headSpeed = newNode;
                       		}
                       		return;
               		}
			previous = current; //sets temp variable for inserting
               		current = current->nextSpeed; //sets current to next current for traversing
	      	 }	
       		 previous->nextSpeed = newNode; //previous->next would be the last position in list.
	}
}

//removeSector will find, unlink, and remove the match in the ordered list. 
void linkedlist::removeSector(int sec)
{
	if(!headSector)
	{
		cout << "list is empty." << endl;
		return;		
	}

	Node* deleteptr = nullptr;
	Node *current = headSector;
	Node *previous = nullptr;
	bool found = false;

	while(current && !found)
	{
		if(current->data->getSector() == sec)
		{
			if(!previous)
			{
				headSector = headSector->nextSector;
			}
			else
			{
				previous->nextSector = current->nextSector;
			}
			deleteptr = current;
			found = true;
		}

		else
		{
			previous = current;
			current = current->nextSector;
		}
	}

		
	found =false;
	previous = nullptr;
	current = headExposure;
	while(current && !found)
	{
	  if(current == deleteptr)
		{
			if(!previous)
			{
				headExposure = headExposure->nextExposure;
			}
			else
			{
				previous->nextExposure = current->nextExposure;
			}
			found = true;
		}
		else
		{
			previous = current;
			current = current->nextExposure;
		}
	}

	found = false;
	previous = nullptr;
	current = headSpeed;
	
	while(current && !found)
	{
		if(current == deleteptr)
		{
			if(!previous)
			{
				headSpeed = headSpeed->nextSpeed;
			}
			else
			{
				previous->nextSpeed = current->nextSpeed;
			}
			found = true;
		}
		else
		{
			previous = current;
			current = current->nextSpeed;
		}
	
	}

	delete deleteptr->data;
	delete deleteptr;
}

bool linkedlist::containSector(int sec)
{
	bool contain = false;

	if(!headSector)
	{
		contain = false;
	}

	Node *current=headSector;	
	while(current)
	{
		if(current->data->getSector() == sec)
		{	
			contain=true;
		}
		current = current->nextSector;
	}

	return contain;
}


void linkedlist::printOrderSector()
{
	Node* current = headSector;
	cout << "Data by Sector" << endl;
	while (current)
	{
		cout << "Sector: #" << current->data->getSector() << " " <<
			current->data->getExposure() << "% exposure, " << current->data->getSpeed() << " " <<
			"km/hr windspeed" << endl;
		current = current->nextSector;

	}
}

void linkedlist::printOrderExposure()
{
	Node* current = headExposure;

	cout << "Data by Exposure" << endl;
	current = headExposure;
	while (current)
	{
		cout << "Sector: #" << current->data->getSector() << " " <<
		current->data->getExposure() << "% exposure, " << current->data->getSpeed() << " " <<
		"km/hr windspeed" << endl;

		current = current->nextExposure;
	}
}

void linkedlist::printOrderSpeed()
{
	Node* current = headSpeed;
	cout << "Data by Speed" << endl;

	while (current)
	{
		cout << "Sector: #" << current->data->getSector() << " " <<
		current->data->getExposure() << "% exposure, " << current->data->getSpeed() << " " <<
		"km/hr windspeed" << endl;

		current = current->nextSpeed;
	}
}

void linkedlist:: printAvgPerSector()
{
	cout << "----------------------------------------------------------------------" << endl
	<< "Averages per sector" << endl <<
	"----------------------------------------------------------------------" << endl;


	Node* current = headSector;
	Node* previous = nullptr;
	int totalExposure = 0;
	int totalSpeed = 0;
	int counter = 0;
	int compareChecker = 1;

	while (current)
	{
		if(current->data->getSector() == compareChecker)
		{
			counter++;
			totalExposure = totalExposure + current->data->getExposure();
			totalSpeed = totalSpeed + current->data->getSpeed();
			if(current->nextSector ==nullptr)
			{
				cout << "Sector: #" << compareChecker << " " << totalExposure / counter << "% exposure, "
				<< totalSpeed / counter << " km/hr windspeed" << endl;

				return;
			}
		
			current = current->nextSector;
		}

		if (current->data->getSector() > compareChecker)
		{
			if(counter==0)
			{
				cout << "Sector: #" << compareChecker << "  -- no data -- " << endl;
                                compareChecker++;
			}
			else
			{
				cout << "Sector: #" << compareChecker << " " << totalExposure / counter << "% exposure, "
				<< totalSpeed / counter << " km/hr windspeed" << endl;
				compareChecker++;
				totalExposure = 0;
				totalSpeed = 0;
				counter = 0;
			}
		}
	}
}

void linkedlist::printHistogramExposure()
{	
	cout << "----------------------------------------------------------------------" << endl <<
		"Histogram data for exposure" << endl
		<< "----------------------------------------------------------------------" << endl;

	int compareExposure = 1;
	int freq = 0;

	Node * current = headExposure;
	Node* previous = nullptr;
	while (current)
	{
		if (current->data->getExposure() == compareExposure)
		{
			freq++;
			if (current->nextExposure != nullptr)
			{
				current = current->nextExposure;
			}
			else
			{
				cout << compareExposure << ", " << freq << endl;
				return;
			}
		}
		if (current->data->getExposure() > compareExposure)
		{
			cout << compareExposure << ", " << freq << endl;
			freq = 0;
			compareExposure++;
		}
	
	}
}

void linkedlist::printHistogramSpeed()
{
        cout << "----------------------------------------------------------------------" << endl <<
        "Histogram data for speed" << endl
        << "----------------------------------------------------------------------" << endl;

        int compareSpeed = 1;
        int freq = 0;

        Node * current = headSpeed;
        Node* previous = nullptr;
        while (current)
        {
                if (current->data->getSpeed() == compareSpeed)
                {
                        freq++;
                        if (current->nextSpeed != nullptr)
                        {
                                current = current->nextSpeed;
                        }
                        else
                        {
                                cout << compareSpeed << ", " << freq << endl;
                                return;
                        }
                }
                if (current->data->getSpeed() > compareSpeed)
                {
                        cout << compareSpeed << ", " << freq << endl;
                        freq = 0;
                        compareSpeed++;
                }

        }

}

//the Main Print function that aggregates the other print functions into one report. 
void linkedlist::printList()
{
	cout << "----------------------------------------------------------------------" << endl
	 << "Data values" << endl <<
	"----------------------------------------------------------------------" << endl;
  		
	printOrderSector();
	printOrderExposure();
	printOrderSpeed();
	printAvgPerSector();
	printHistogramExposure();
	printHistogramSpeed();	
	
}
	
void linkedlist::printSectorList()
{	
	if(!headSector)
	{
		return;
	}
	
	Node*current = headSector;
	while(current->nextSector != nullptr)
	{
		cout <<current->data->getSector() << ", ";
		current= current->nextSector;
	}
	cout << current->data->getSector() << endl;	
}
