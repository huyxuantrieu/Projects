//Huy Trieu. This is a Time Sheet Program. The user will be prompt to choose to add a new entry (includes Name, Department, and Hours), print existing entries, delete an entry, or quit.

using namespace std;
#include <iostream>
#include <string>
const int MAX = 100;

struct timeSheet
{
	string name;
	string department;
	float hours;
};

void menu()
{
	cout << endl << "MENU" << endl << "1 - Add new entry" << endl << "2 - Print out existing entries" << endl <<
		"3 - Delete an entry" << endl << "4 - Quit program" << endl << "Please enter a choice (1 to 4)" << endl;
}

void checkChoice(int& choice) // checks to make sure choice doesnt fail and that it is between 1 and 4.
{
	cin >> choice;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option";
		cin >> choice;
	}

	while (choice >= 5 || choice < 1) // ensure variable 'choice' is between 1 and 4 to match the options.
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option" << endl;
		cin >> choice;
	}
	cin.ignore(100, '\n');
}

void checkHours(timeSheet enterTime[], int& counter) // ensure hours is a number. 
{
	cin >> enterTime[counter].hours;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option\n";
		cin >> enterTime[counter].hours;
	}
}

void checkaddAnother(char& addAnother, timeSheet enterTime[], int& choice, int& counter) // ensures 'addAnother' doesnt fail and is either a y or n only. 
{
	cout << "Do you want to continue? ('y' or 'n')" << endl;
	cin >> addAnother;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option \n";
		cin >> addAnother;
	}

	while (addAnother != 'y' && addAnother != 'n') // ensure addAnother stores a 'y' or 'n' only. 
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option\n";
		cin >> addAnother;
	}


}


void loadData(char& addAnother, timeSheet enterTime[], int& choice, int& counter) // function to get user to enter the data in. 
{
	cout << "Enter employee name: ";
	getline(cin, enterTime[counter].name);

	cout << "Enter the department: ";
	getline(cin, enterTime[counter].department);

	cout << "Enter amount of hours: ";
	checkHours(enterTime, counter);
	counter++;

	checkaddAnother(addAnother, enterTime, choice, counter); // ensures fails and user types only y or n. 
	cin.ignore(100, '\n');
}


void checkdeleting(int& deleting, int& entryCounter, int& counter) // verifying on which entry user can delete.
{
	cout << endl << "Which entry would you like to delete?" << endl;
	cin >> deleting;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid option \n";
		cin >> deleting;
	}

	while (counter == 0) // if there are no entries, this will tell user and then go back to the menu. 
	{
		cout << "There are no entries to delete. Please enter an entry before using this option." << endl;
		break;
	}

	if (counter != 0)
	{
		while (deleting >= entryCounter || deleting < 0) // make sure user isn't deleting an entry that doesn't exist.
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "please enter a valid option \n";
			cin >> deleting;
		}
	}
}

void deleteProcess(int& deleting, int& entryCounter, int& counter, timeSheet enterTime[]) // replacing the element being deleted by the element ahead of it then lowering the total amount of entries
{
	if (counter != 0)
	{
		for (int i = deleting; i < entryCounter; i++)
		{
			enterTime[i].name = enterTime[i + 1].name;
			enterTime[i].department = enterTime[i + 1].department;
			enterTime[i].hours = enterTime[i + 1].hours;
		}

		entryCounter--;	// lowers the counter by 1 to not print out blank or duplicates after deletion. 
		counter--;
		cout << "Entry " << deleting << " has been deleted.\n";
	}
}

void choicesOutcome(int& deleting, int& entryCounter, char& addAnother, timeSheet enterTime[], int& choice, int& counter) // 
{
	if (choice == 1)
	{
		do
		{
			loadData(addAnother, enterTime, choice, counter); // if user enters 1, it will go to loadData (getting user to enter in more information). 
		} while (addAnother == 'y'); //This will repeat if user enters y for adding another
	}

	else if (choice == 2)	// prints out the current list. 
	{
		for (entryCounter = 0; entryCounter < counter; entryCounter++)
		{
			cout << endl << endl << "----- Entry " << entryCounter << " -----" << endl << "Name: " << enterTime[entryCounter].name << endl << "Department: " << enterTime[entryCounter].department << endl << "Hours: " << enterTime[entryCounter].hours << endl;
		}
	}

	else if (choice == 3) // prints out the current list then prompts user to enter in which entry to delete. 
	{
		for (entryCounter = 0; entryCounter < counter; entryCounter++)
		{
			cout << endl << "----- Entry " << entryCounter << " -----" << endl << "Name: " << enterTime[entryCounter].name << endl << "Department: " << enterTime[entryCounter].department << endl << "Hours: " << enterTime[entryCounter].hours << endl;
		}
		checkdeleting(deleting, entryCounter, counter);
		deleteProcess(deleting, entryCounter, counter, enterTime);
	}
}


int main()
{
	int deleting;
	int entryCounter;
	char addAnother;
	timeSheet enterTime[MAX];
	int choice;
	int counter = 0;
	cout << "*** Time Sheet ***" << endl;
	do
	{
		menu();
		checkChoice(choice); // checks if choice is 1 to 4
		choicesOutcome(deleting, entryCounter, addAnother, enterTime, choice, counter);

	} while (choice != 4);

	cout << endl << "The program will quit. Thanks for using my Time Sheet Program! \n";
	return 0;

}