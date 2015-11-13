/*
* Container.h
*
*  Created on: Nov 2, 2015
*      Author: Mustafa Zaban
*      IDE: Eclipse
*/
#include <iostream>  //fundamental input/output library

using namespace std;

#ifndef CONTAINER_H_
#define CONTAINER_H_


class Container {

public:
	Container();  //constructor
	virtual ~Container();  //destructor
	Container & operator=(Container &); //operator=
	Container(Container &);  //copy constructor
	
	//element adding functions
	void putElementAtBegin(int);
	void putElementAtEnd(int);
	//                       value,position
	void putElementAtPostition(int, int);


	//element getting functions
	int getFirstElement();  //pop the first element
	int getLastElement();   //pop the last element
	int getElementsValueAt(int);  //get the Nth elements value

	//other functions
	bool isEmpty();  //check if the container is empty
	int getSize();   //gets the containers size
	void clear();    //clear the container


private:

	int c_size;  //containers size

	struct Element  //elements structure (the node from container chain)
	{
		int e_value;
		Element * e_next;
		Element * e_previus;
		unsigned int e_number;
	};

	Element * c_First; //points to the first element
	Element * c_Last;  //points to the last element


};

#endif /* CONTAINER_H_ */
