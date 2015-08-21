#include "ComplexNumber.h"


ComplexNumber::ComplexNumber()
{
	setReal(0);
	setImaginery(0);
}

ComplexNumber::ComplexNumber(const int real, const int imaginery)
{
	setReal(real);
	setImaginery(imaginery);
}

ComplexNumber::ComplexNumber(const ComplexNumber & rhs)
{
	this->n_real = rhs.n_real;
	this->n_imgnry = rhs.n_imgnry;
}

void ComplexNumber::setReal(const int real)
{
	this->n_real = real;
}

void ComplexNumber::setImaginery(const int imaginery)
{
	this->n_imgnry = imaginery;
}

int ComplexNumber::getReal()
{
	return this->n_real;
}

int ComplexNumber::getImagienry()
{
	return this->n_imgnry;
}


ComplexNumber ComplexNumber::operator+ (const ComplexNumber & rhs)
{
	ComplexNumber *to_return = new ComplexNumber;
	to_return->n_real = this->n_real + rhs.n_real;
	to_return->n_imgnry = this->n_imgnry + rhs.n_imgnry;
	return *to_return;
	delete to_return;
}

ComplexNumber ComplexNumber::operator= (const ComplexNumber & rhs)
{
	this->n_real = rhs.n_real;
	this->n_imgnry = rhs.n_imgnry;
	return *this;
}

void ComplexNumber::showNumber()
{
	cout << "C = " << this->getReal() << " + i(" << this->getImagienry() << ")"<<endl;
}

bool ComplexNumber::operator== (const ComplexNumber & rhs)
{
	if (this->n_real == rhs.n_real && this->n_imgnry == rhs.n_imgnry)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ComplexNumber::operator!= (const ComplexNumber & rhs)
{
	if (!(*this == rhs))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream & operator<< (ostream &output, ComplexNumber &rhs)
{
	output << "C = " << rhs.getReal() << " + i(" << rhs.getImagienry() << ")" << endl;
	return output;
}

istream & operator>> (istream &input, ComplexNumber &rhs)
{
	int tmp_real(0);
	int tmp_imaginery(0);
	
	cout << "Enter the complex numbers real part:";
	cin >> tmp_real;
	rhs.setReal(tmp_real);
	cout << "Enter the complex numbers imaginery part:";
	cin >> tmp_imaginery;
	rhs.setImaginery(tmp_imaginery);
	return input;
}
	