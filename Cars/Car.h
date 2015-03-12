#include <iostream>
#include <string>

using namespace std;

class Car {

	friend ostream & operator<< ( ostream &, Car & ); //cout implementation for custom object class "Car"
	friend istream & operator>> ( istream &, Car & ); //cin implementation for custom object class "Car"

private:
	// custom object members
	string m_sBrand;
	string m_sModel;
	int m_nYear;
	double m_dConsumption;
	string m_sColor;

public:
	Car( ); //default constructor
	Car( string, string, int, double, string ); //custom constructor with full range of private members
	Car( const Car & ); //copy constructor

	//setters for all private members
	void setBrand ( string );
	void setModel ( string );
	void setYear ( int );
	void setConsumption ( double );
	void setColor ( string );

	//getters for all private members
	string getBrand ( );
	string getModel ( );
	int getYear ( );
	double getConsumption ( );
	string getColor ( );

	//predefined operator = for custom class "Car"
	Car operator= ( const Car & );

	//predefined operator == for custom class "Car"
	bool operator== ( const Car & ) const;

	//predefined operator != for custom class "Car"
	bool operator!= ( const Car & ) const;
};
