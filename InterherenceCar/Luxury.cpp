#include <iostream>
#include <string>
using namespace std;

#include "Luxury.h"


Luxury::Luxury(const string& brnd, const string& mdl, const string& knd, const string& clr, const int& chnmbr, const string& crnmbr, const double& olcst, double rdlnght, double txprdy, int usddys, string prmm)
	: Auto (brnd, mdl, knd, clr, chnmbr, crnmbr, olcst)
{
	setRoadLenght (rdlnght);
	setTaxPerDay (txprdy);
	setUsedDays (usddys);
	setPremium (prmm);

}


void Luxury::setRoadLenght (double rdlnght)
{
	roadLenght = rdlnght;
}

void Luxury::setTaxPerDay (double txprdy)
{
	taxPerDay = txprdy;
}

void Luxury::setUsedDays (int usddys)
{
	usedDays = usddys;
}

void Luxury::setPremium (string prmm)
{
	premium = prmm;
}

double Luxury::getRoadLenght ()
{
	return roadLenght;
}

double Luxury::getTaxPerDay ()
{
	return taxPerDay;
}

int Luxury::getUsedDays ()
{
	return usedDays;
}

string Luxury::getPremium ()
{
	return premium;
}

void Luxury::getPayment  ()
{
	int premiumMulty;
	
	if (getPremium() == "Shampansko")
	{
		premiumMulty = 100;
	}
	else if (getPremium() == "Vino")
	{
		premiumMulty = 50;
	}
	else
	{
		premiumMulty = 40;
	}

	if (getRoadLenght() < 200)
	{
		cout << "The rent for this car is - " << 0.6*getTaxPerDay()*getUsedDays()+premiumMulty << endl;
	}
	else
	{
		cout << "The rent for this car is - " << 0.4*getTaxPerDay()*getUsedDays()+premiumMulty << endl;
	}
}