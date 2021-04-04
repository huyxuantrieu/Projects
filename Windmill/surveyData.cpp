#include "surveyData.h" 

surveyData::surveyData(int sec, int exp, int spd)
{
	setSector(sec);
	setExposure(exp);
	setSpeed(spd);	
}

//-----SETTERS-----
void surveyData::setSector(int sec)
{
	sector = sec;
}

void surveyData::setExposure(int exp)
{
	exposure = exp;
}

void surveyData::setSpeed(int spd)
{
	speed = spd;
}

//-----GETTERS-----
int surveyData::getSector()
{
	return sector;
}

int surveyData::getExposure()
{
	return exposure;
}

int surveyData::getSpeed()
{
	return speed;
}
