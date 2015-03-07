#include <iostream>
#include <string>

#include "Car.h"

using namespace std;


Car::Car()
{
	brand = " ";
	model = " ";
	year = 0;
	consumption = 0;
	color = " ";
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
	this->brand = rhs.brand;
	this->model = rhs.model;
	this->year = rhs.year;
	this->consumption = rhs.consumption;
	this->color = rhs.color;
}

void Car::setBrand ( string brnd )
{
	brand = brnd;
}

void Car::setModel ( string mdl )
{
	model = mdl;
}

void Car::setYear ( int yr )
{
	if (( yr < 1900)||( yr > 2015))
	{
		year = 1900;
	}
	else
	{
		year = yr;
	}
}

void Car::setConsumption ( double cnsmptn )
{
	if (cnsmptn < 0)
	{
		consumption = 0;
	}
	else
	{
		consumption = cnsmptn;
	}
}

void Car::setColor ( string clr)
{
	color = clr;
}

ostream &operator<< ( ostream &output, Car & rhs)
{
	output << rhs.brand << " " << rhs.model << " " << rhs.year << " " << rhs.consumption << " " << rhs.color;
	return output;
}

istream &operator>> ( istream &input, Car & rhs )
{
	cin >> rhs.brand;
	cin >> rhs.model;
	cin >> rhs.year;
	cin >> rhs.consumption;
	cin >> rhs.color;
	return input;
}

Car Car::operator= ( const Car & rhs)
{
	this->brand = rhs.brand;
	this->model = rhs.model;
	this->year = rhs.year;
	this->consumption = rhs.consumption;
	this->color = rhs.color;
	return *this;
}

bool Car::operator== ( const Car & rhs)
{
	if((this->brand == rhs.brand)&&(this->model == rhs.model)&&(this->year == rhs.year)&&(this->consumption == rhs.consumption)&&(this->color == rhs.color))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Car::operator!= ( const Car & rhs)
{
	if((this->brand == rhs.brand)&&(this->model == rhs.model)&&(this->year == rhs.year)&&(this->consumption == rhs.consumption)&&(this->color == rhs.color))
	{
		return false;
	}
	else
	{
		return true;
	}
}



