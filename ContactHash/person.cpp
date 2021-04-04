#include "person.h"
#include <iostream>


person& person::operator=(person& orig)
{
	setID(orig.identity);
	setFirstName(orig.firstName);
	setLastName(orig.lastName);
	setFamilyName(orig.familyName);
	return *this;
}

person::person(char* id, char* Fname, char* Lname, char* famName)
{
	identity = nullptr;
	familyName = nullptr;
	firstName = nullptr;
	lastName = nullptr;
	
	setID(id);
	setFirstName(Fname);
	setLastName(Lname);
	setFamilyName(famName);
}

person::person (person& orig)
{
	identity = new char[strlen(orig.identity)+1];
	strcpy(identity, orig.identity);

	familyName = new char[strlen(orig.familyName)+1];
	strcpy(familyName, orig.familyName);

	firstName = new char[strlen(orig.firstName)+1];
	strcpy(firstName, orig.firstName);
	
	lastName = new char[strlen(orig.lastName)+1];
	strcpy(lastName, orig.lastName);	
}
person::person()
{
	identity = new char[10];
	strcpy(identity, "not set");

	familyName = new char[10];
	strcpy(familyName,"not set");

	firstName = new char[10];
	strcpy(firstName, "not set");
	
	lastName = new char[10];
	strcpy(lastName, "not set");
}

person::~person()
{
	delete [] identity;
	delete [] familyName;
	delete [] firstName;
	delete [] lastName;
}

void person::setID(char* id)
{
	int size = strlen(id);
	if(identity)
	{
		delete [] identity;
	}

	identity = new char[size+1];
	strcpy(identity, id);	
}

void person::setFirstName(char* Fname)
{
	int size = strlen(Fname);
	if(firstName)
	{
		delete [] firstName;
	}
	firstName = new char[size+1];
	strcpy(firstName, Fname);
}

void person::setLastName(char* Lname)
{
	int size = strlen(Lname);
	if(lastName)
	{
		delete [] lastName;
	}
	lastName = new char[size+1];
	strcpy(lastName, Lname);
}

void person::setFamilyName(char* famName)
{
	int size = strlen(famName);
	if(familyName)
	{
		delete [] familyName;
	}
	familyName = new char[size+1];
	strcpy(familyName, famName);
}

char* person::getID()
{
	return identity;
}

char* person::getFirstName()
{
	return firstName;
}

char* person::getLastName()
{
	return lastName;
}

char* person::getFamilyName()
{
	return familyName;
}

std::ostream& operator<<(std::ostream& out, const person&p)
{
	out << "ID: " << p.identity << std::endl;
	out << "First Name: " << p.firstName << std::endl;	
	out << "Last Name: " << p.lastName << std::endl;	
	return out;
}

