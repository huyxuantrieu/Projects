#include <cstring>
#pragma once

class plantType
{
	public:
	plantType();
	~plantType();
	plantType(int num, char* seedType);
	plantType(plantType& orig);
	plantType &operator=(plantType& orig);
	void setBoxNum(int num);
	void setSeed(char* seedType);
	int getBoxNum();
	char* getSeed();

	private:
	char* seed;
	int boxNum;

};
