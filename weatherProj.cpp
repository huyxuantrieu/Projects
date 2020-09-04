/* This file will load in a file called 'temps.txt'. then it will store it inside a struct variable that contains 3 members. It will print out the contents in the file
	and print out the highest and lowest temepratures, and its corresponding months. */ 
// Huy Trieu

#include <iostream>
#include <fstream>
using namespace std;

struct Temperature //creating a struct containing 3 members
{
	string month;
	int high;
	int low;
};

//prototype functions
void loadData(ifstream& infile , Temperature temp[], int& size);
Temperature averageHigh(Temperature[], int size);
Temperature averageLow(Temperature[], int size);

int main()
{	
	const int row = 12;
	ifstream infile;
	Temperature temp[row];
	Temperature highTempMnth, lowTempMnth; 
	int size;
	

	loadData(infile, temp, size);

	for (int i = 0; i < 12; i++)
	{
		cout << temp[i].month << " " << temp[i].high << " " << temp[i].low << endl;
	}

	highTempMnth = averageHigh(temp, size); // 'highTempMnth is storing the return value of 'averageHigh' function. its members is used to print the values below
	cout << "The highest temperature is in the month of " << highTempMnth.month << " and is " << highTempMnth.high << endl;
	lowTempMnth = averageLow(temp, size);// 'lowTempMnth is storing the return value of 'averagelow' function. its members is used to print the values below
	cout << "The lowest temperature is in the month of " << lowTempMnth.month << " and is " << lowTempMnth.low << endl;


}

void loadData(ifstream& infile, Temperature temp[], int& size) // loading data from 'temps.txt'. storing it in a Struct Array called 'temp'.
{
	infile.open("temps.txt"); // can use prompt to grab customized file name. 

	if (!infile.is_open())
	{
		cout << "File was not opened succesfully" << endl;
	}
	else
	{
		cout << "File opened sucessfully" << endl;
	}
	size = 0;

	while (!infile.eof())
	{

		infile >> temp[size].month >> temp[size].high >> temp[size].low;
		size++;
	}
};


Temperature averageHigh(Temperature temp[], int size)
{
	int indexOfHighTemp = 0; // will store the Number of the element in the array that contains the highest temperature.
	int hightemp = temp[0].high;
	for (int i = 0; i < size; i++)
	{
		if (temp[i].high > hightemp)
		{
			hightemp = temp[i].high;
			indexOfHighTemp = i;
		}
	}
	return temp[indexOfHighTemp]; 
}


Temperature averageLow(Temperature temp[], int size)// will store the Number of the element in the array that contains the lowest temperature.
{
	int indexOfLowTemp = 0;
	int lowtemp = temp[0].low;
	for (int i = 0; i < size; i++)
	{
		if (temp[i].low < lowtemp) 
		{
			lowtemp = temp[i].low;
			indexOfLowTemp++;
		}
	}
	return temp[indexOfLowTemp]; 
}

