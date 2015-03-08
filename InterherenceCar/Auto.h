#pragma once

#include <iostream>
#include <string>
using namespace std;

class Auto
{
private:
	string brand;
	string model;
	string kind;
	string color;
	int chNumber;
	string carNumber;
	double oilCost;
public:
	Auto (string, string, string, string, int, string, double);
	Auto();
	
	void setBrand (string);
	void setModel (string);
	void setKind (string);
	void setColor (string);
	void setChNumber (int);
	void setCarNumber (string);
	void setOilCost (double);

	string getBrand ();
	string getModel ();
	string getKind ();
	string getColor ();
	int getChNumber ();
	string getCarNumber ();
	double getOilCost ();

	virtual void getPayment() = 0;
	
};

