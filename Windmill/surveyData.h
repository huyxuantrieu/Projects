#pragma once


class surveyData
{
	public:
	surveyData(int sec, int exp, int spd);
	
	//setters
	void setSector(int sec);
	void setExposure(int exp);
	void setSpeed(int spd);
	
	//getters
	int getSector();
	int getExposure();
	int getSpeed();
	
	private:
	int sector;
	int exposure;
	int speed;
};
