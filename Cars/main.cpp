#include <iomanip> //formats cout output
#include <fstream> //write/read files (.dat, .txt & more)
#include <cstdlib> //used for exit(1) operator at line 38
#include <vector> //vector container
#include <iterator> //iterator - to explore object in custom class vector, useful with ostream and istream functions

#include "Car.h"


enum requestType {
	CREATE_A_CAR = 1,
	WRITE_A_CARS,
	SHOW_THE_FILE,
	SEARCH_BY_BRAND,
	SEARCH_BY_LOWEST_CONSUMPTION,
	EXIT
};

void outputLine ( const string, const string, const int, const double, const string ); //format output vision for cout

int getRequest (); //get users request for program actions

void ShowTableHeader (); //show some strings - BRAND MODEL and other


int main()
{
	vector<Car> carsVector; //creates container
	vector<Car>::iterator carsIterator; //creates iterator

	//file creating
	ofstream ofsInCars("cars.dat", ios::out);
	ifstream ifsInCars("cars.dat", ios::in);

	if (!ofsInCars) //checking for file's correct work
	{
		cout << "The file could not be opened!" << endl;
		exit(1);
	} else {
		cout << "The file is opened!" << endl;
	}

	//creating temporary input object elements
	string brand = " ";
	string model = " ";
	int year = 0;
	double consumption = 0;
	string color = " ";
	//end of temporary object


	int request; //temporary int for request function

	request = getRequest(); //furst time use request function to enter in program body

	// program loop
	while (request != EXIT) {
		int carsCount = 0;
		Car tempCar;
		string tempBrand = " ";
		int tempConsumption = 1000;

		switch (request) {

		case CREATE_A_CAR:
			cout<< "\nEnter the number of cars who will be added to your list:";
			cin >> carsCount;

			while (carsCount != 0)
			{
				cout<< "\nEnter your cars details by this order - brand model year consumption color:"<< endl;
				cin >> tempCar;
				carsVector.push_back(tempCar);
				carsCount--;
			}
			break;

		case WRITE_A_CARS:
			for (carsIterator = carsVector.begin(); carsIterator!= carsVector.end(); ++carsIterator)
			{
				ofsInCars << *carsIterator << endl;
			}

			cout << "\nThe cars are writen to the file!" << endl;
			carsVector.clear();
			break;

		case SHOW_THE_FILE:

			ifsInCars.clear();
			ifsInCars.seekg(0);

			ShowTableHeader ();

			while (ifsInCars >> brand >> model >> year >> consumption >> color)
			{
				outputLine(brand, model, year, consumption, color);
			};
			break;

		case SEARCH_BY_BRAND:
			cout << "\nEnter your searched brand: ";
			cin >> tempBrand;
			cout << "\nAll cars by brand - " << tempBrand << ":" << endl;

			ifsInCars.clear();
			ifsInCars.seekg(0);

			ShowTableHeader ();

			while (ifsInCars >> brand >> model >> year >> consumption >> color)
			{
				if (tempBrand == brand)
				{
					outputLine(brand, model, year, consumption, color);
				}
			};
			break;

		case SEARCH_BY_LOWEST_CONSUMPTION:
			cout << "\nThe cars with lowest consumption:" << endl;

			ifsInCars.clear();
			ifsInCars.seekg(0);

			while (!ifsInCars.eof())
			{
				ifsInCars >> brand >> model >> year >> consumption >> color;

				if (tempConsumption > consumption)
				{
					tempConsumption = consumption;
				}
			};

			ifsInCars.clear();
			ifsInCars.seekg(0);

			ShowTableHeader ();
			while (ifsInCars >> brand >> model >> year >> consumption >> color)
			{
				if (tempConsumption == consumption)
				{
					outputLine(brand, model, year, consumption, color);
				}
			};
			break;
		}
		request = getRequest(); //repeat the program body cycle
	}


	return 0;
}

void outputLine(const string brand, const string model, const int year, const double consumption, const string color)
{
	cout << left << setw(11) << brand << setw(12) << model << setw(10) << year << setw(14) << consumption << setw(10) << color << endl;
}

int getRequest() {
	int request;
	cout << "\n\nMake your choice:" << endl
			<< "1 - Create a car/s" << endl
			<< "2 - Write car/s" << endl
			<< "3 - Show cars" << endl
			<< "4 - Search by brand" << endl
			<< "5 - Search by less consumption" << endl
			<< "6 - Exit!" << endl;
	do
	{
		cout << "\n? - ";
		cin >> request;
	} while (request < CREATE_A_CAR && request > EXIT);

	return request;
}

void ShowTableHeader ()
{
	cout << left << setw(11) << "BRAND" << setw(12) << "MODEL" << setw(10) << "YEAR" << setw(14) << "CONSUMPTION" << setw(10) << "COLOR" << endl;
}
