#include "Auto.h"

class Family :	public Auto
{
private:
	double roadLenght;
	double taxPerDay;
	int usedDays;
public:
	Family (const string&, const string&, const string&, const string&, const int&, const string&, const double&, double, double, int);
	Family();
	

	virtual void getPayment();

	void setRoadLenght (double);
	void setTaxPerDay (double);
	void setUsedDays (int);

	double getRoadLenght ();
	double getTaxPerDay ();
	int getUsedDays ();
};

