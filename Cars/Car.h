#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car
{
	friend ostream &operator<< ( ostream &, Car & );
	friend istream &operator>> ( istream &, Car & );

private:
	
	string brand;
	string model;
	int year;
	double consumption;
	string color;

public:
	
	Car ();
	Car ( string, string, int, double, string );
	Car ( const Car & );
	
	void setBrand ( string );
	void setModel ( string );
	void setYear ( int );
	void setConsumption ( double );
	void setColor ( string );

	string getBrand ();
	string getModel ();
	int getYear ();
	double getConsumption ();
	string getColor ();

	Car operator= ( const Car & );
	bool operator== ( const Car & ) const;
	bool operator!= ( const Car & ) const;



};

