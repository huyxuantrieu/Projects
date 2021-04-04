#include "plantType.h"


plantType::plantType()
{
	seed = new char[10];
	strcpy(seed, "not set");
	boxNum = 0;
}

plantType::plantType(int num, char* seedType)
{
	seed = nullptr;
	boxNum = 0;
	setBoxNum(num);
	setSeed(seedType);
}

plantType& plantType::operator=(plantType& orig)
{
	setSeed(orig.seed); // since its a pointer, we need an operator for this
	setBoxNum(orig.boxNum);//not sure
	return *this;
}

plantType::plantType(plantType& orig)
{
	seed = new char [strlen(orig.seed)+1];
	strcpy(seed, orig.seed); // not sure
	boxNum = orig.boxNum;
}

plantType::~plantType()
{
	delete [] seed;
}

void plantType::setBoxNum(int num)
{
	boxNum = num;	
}

void plantType::setSeed(char* seedType)
{
	int size = strlen(seedType);
	delete [] seed;
	seed = new char[size+1];
	strcpy(seed, seedType);
}

int plantType::getBoxNum()
{
	return boxNum;
}

char* plantType::getSeed()
{
	return seed;
}

