#include "Auto.h"


Auto::Auto (string brand, string model, string kind, string color, int chnumber, string carnumber, double oilcost)
{
	setBrand (brand);
	setModel (model);
	setKind (kind);
	setColor (color);
	setChNumber (chnumber);
	setCarNumber (carnumber);
	setOilCost (oilcost);
}

Auto::Auto()
{
	m_sBrand = " ";
	m_sModel = " ";
	m_sKind = " ";
	m_sColor = " ";
	m_nChNumber = 0;
	m_sCarNumber = " ";
	m_dOilCost = 0;
}
	
void Auto::setBrand (string brand)
{
	m_sBrand = brand;
}
	
void Auto::setModel (string model)
{
	m_sModel = model;
}

void Auto::setKind (string kind)
{
	m_sKind = kind;
}

void Auto::setColor (string color)
{
	m_sColor = color;
}

void Auto::setChNumber (int chnumber)
{
	m_nChNumber = chnumber;
}

void Auto::setCarNumber (string carnumber)
{
	m_sCarNumber = carnumber;
}

void Auto::setOilCost (double oilcost)
{
	m_dOilCost = oilcost;
}


string Auto::getBrand ()
{
	return brand;
}

string Auto::getModel ()
{
	return m_sModel;
}

string Auto::getKind ()
{
	return m_sKind;
}

string Auto::getColor ()
{
	return m_sColor;
}

int Auto::getChNumber ()
{
	return m_nChNumber;
}

string Auto::getCarNumber ()
{
	return m_sCarNumber;
}

double Auto::getOilCost ()
{
	return m_dOilCost;
}
