#include <iostream>
#include <string>

#include "Car.h"

using namespace std;


Car::Car()
{
	m_sBrand = " ";
	m_sModel = " ";
	m_nYear = 0;
	m_dConsumption = 0;
	m_sColor = " ";
}

Car::Car ( string brnd, string mdl, int yr, double cnsmptn, string clr )
{
	setBrand ( brnd );
	setModel ( mdl );
	setYear ( yr );
	setConsumption ( cnsmptn );
	setColor ( clr );
}

Car::Car ( const Car & rhs)
{
	this->m_sBrand = rhs.m_sBrand;
	this->m_sModel = rhs.m_sModel;
	this->m_nYear = rhs.m_nYear;
	this->m_dConsumption = rhs.m_dConsumption;
	this->m_sColor = rhs.m_sColor;
}

void Car::setBrand ( string brand )
{
	m_sBrand = brand;
}

void Car::setModel ( string model )
{
	m_sModel = model;
}

void Car::setYear ( int year )
{
	if (( year < 1900)||( year > 2015))
	{
		m_nYear = 1900;
	}
	else
	{
		m_nYear = year;
	}
}

void Car::setConsumption ( double consumption )
{
	if (consumption < 0)
	{
		m_dConsumption = 0;
	}
	else
	{
		m_dConsumption = consumption;
	}
}

void Car::setColor ( string color)
{
	m_sColor = color;
}

ostream &operator<< ( ostream &output, Car & rhs)
{
	output << rhs.m_sBrand << " " << rhs.m_sModel << " " << rhs.m_nYear << " " << rhs.m_dConsumption << " " << rhs.m_sColor;
	return output;
}

istream &operator>> ( istream &input, Car & rhs )
{
	cin >> rhs.m_sBrand;
	cin >> rhs.m_sModel;
	cin >> rhs.m_nYear;
	cin >> rhs.m_dConsumption;
	cin >> rhs.m_sColor;
	return input;
}

Car Car::operator= ( const Car & rhs)
{
        this->m_sBrand = rhs.m_sBrand;
	this->m_sModel = rhs.m_sModel;
	this->m_nYear = rhs.m_nYear;
	this->m_dConsumption = rhs.m_dConsumption;
	this->m_sColor = rhs.m_sColor;
	return *this;
}

bool Car::operator== ( const Car & rhs) const
{
	if((this->m_sBrand == rhs.m_sBrand)&&(this->m_sModel == rhs.m_sModel)&&(this->m_nYear == rhs.m_nYear)&&(this->m_dConsumption == rhs.m_dConsumption)&&(this->m_sColor == rhs.m_sColor))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Car::operator!= ( const Car & rhs) const
{
	if(!(*this == rhs)) //need to chek
	{
		return true;
	}
	else
	{
		return false;
	}
	
}



