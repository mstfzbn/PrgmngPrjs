#include "Auto.h"

class Luxury :	public Auto
{
private:
	double roadLenght;
	double taxPerDay;
	int usedDays;
	string premium;
public:
	Luxury (const string&, const string&, const string&, const string&, const int&, const string&, const double&, double, double, int, string);
	Luxury();

	virtual void getPayment ();

	void setRoadLenght (double);
	void setPremium (string);
	void setTaxPerDay (double);
	void setUsedDays (int);

	double getRoadLenght ();
	double getTaxPerDay ();
	int getUsedDays ();
	string getPremium ();
	
};

