#include <iostream>
#include <string>
using namespace std;

#include "Family.h"


Family::Family (const string& brnd, const string& mdl, const string& knd, const string& clr, const int& chnmbr, const string& crnmbr, const double& olcst, double rdlnght, double txprdy, int usddys)
	:Auto (brnd, mdl, knd, clr, chnmbr, crnmbr, olcst)
{
	setRoadLenght (rdlnght);
	setTaxPerDay (txprdy);
	setUsedDays (usddys);
}

Family::Family()
{
}
	

void Family::setRoadLenght (double rdlnght)
{
	roadLenght = rdlnght;
}

void Family::setTaxPerDay (double txprdy)
{
	taxPerDay = txprdy;
}

void Family::setUsedDays (int usddys)
{
	usedDays = usddys;
}

double Family::getRoadLenght ()
{
	return roadLenght;
}

double Family::getTaxPerDay ()
{
	return taxPerDay;
}

int Family::getUsedDays ()
{
	return usedDays;
}

void Family::getPayment ()
{
	if (getRoadLenght() < 500)
	{
		cout << "The rent for this car is - " << 0.7*getTaxPerDay()*getUsedDays() << endl;
	}
	else
	{
		cout << "The rent for this car is - " << 0.4*getTaxPerDay()*getUsedDays() << endl;
	}
}