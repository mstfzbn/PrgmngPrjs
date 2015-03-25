#pragma once

#include <iostream>    //standart i/o library
#include <string>      //string library
using namespace std;   //standart namespace 

class Auto
{
private:
	string m_sBrand;
	string m_sModel;
	string m_sKind;
	string m_sColor;
	int m_nChNumber;
	string m_sCarNumber;
	double m_dOilCost;
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

	virtual void getPayment() = 0;   //virtual function on the major class wich will be realized in all child classes
	
};

