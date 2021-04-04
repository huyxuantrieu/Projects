#include <cstring>
#include <iostream>

#pragma once

class person
{
	public:
	person(char* id, char* Fname, char* Lname, char* famName);
	void setID(char* id);
	void setFirstName(char* Fname);
	void setLastName(char* Lname);
	void setFamilyName(char* famName);

	char* getID();
	char* getFirstName();
	char* getLastName();
	char* getFamilyName();
	
	person &operator=(person &orig);
	person(person &orig);	
	person();
	~person();
	

	friend std::ostream& operator<<(std::ostream& out,const person& p);
	private:
	char* firstName;
	char* identity;
	char* lastName;
	char* familyName;
	
};
