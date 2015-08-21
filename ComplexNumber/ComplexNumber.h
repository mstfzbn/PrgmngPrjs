#include <iostream>   //included for istream and ostream functions

using namespace std;  //used for istream and ostream functions

class ComplexNumber
{
    friend ostream & operator<< (ostream &, ComplexNumber &);  //overloading for cout << operator
    friend istream & operator>> (istream &, ComplexNumber &);  //overloading for cin >> operator


public:
	ComplexNumber();                      //default constructor
	ComplexNumber(const int, const int);  //regular constructor
	ComplexNumber(const ComplexNumber &); //copy constructor 

	void setReal(const int);           //real part setter
	void setImaginery(const int);      //imaginery part setter

	int getReal();               //real part getter
	int getImagienry();          //imaginery part getter

	void showNumber();           //custom function

	ComplexNumber  operator+ (const ComplexNumber &);  //operator + overloading
	ComplexNumber  operator= (const ComplexNumber &);  //operator = overloading

	bool operator== (const ComplexNumber &);           //operator == overloading
	bool operator!= (const ComplexNumber &);           //operator != overloading

private:
	int n_real;     //private member for real part
	int n_imgnry;   //private member for imaginery part
};

