#include "Auto.h"


Auto::Auto (string brnd, string mdl, string knd, string clr, int chnmbr, string crnmbr, double olcst)
{
	setBrand (brnd);
	setModel (mdl);
	setKind (knd);
	setColor (clr);
	setChNumber (chnmbr);
	setCarNumber (crnmbr);
	setOilCost (olcst);
}

Auto::Auto()
{
	brand = " ";
	model = " ";
	kind = " ";
	color = " ";
	chNumber = 0;
	carNumber = " ";
	oilCost = 0;
}
	
void Auto::setBrand (string brnd)
{
	brand = brnd;
}
	
void Auto::setModel (string mdl)
{
	model = mdl;
}

void Auto::setKind (string knd)
{
	kind = knd;
}

void Auto::setColor (string clr)
{
	color = clr;
}

void Auto::setChNumber (int chnmbr)
{
	chNumber = chnmbr;
}

void Auto::setCarNumber (string crnmbr)
{
	carNumber = crnmbr;
}

void Auto::setOilCost (double olcst)
{
	oilCost = olcst;
}


string Auto::getBrand ()
{
	return brand;
}

string Auto::getModel ()
{
	return model;
}

string Auto::getKind ()
{
	return kind;
}

string Auto::getColor ()
{
	return color;
}

int Auto::getChNumber ()
{
	return chNumber;
}

string Auto::getCarNumber ()
{
	return carNumber;
}

double Auto::getOilCost ()
{
	return oilCost;
}
