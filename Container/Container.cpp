#include "Container.h"

Container::Container()
{
	c_First = c_Last = NULL;
	c_size = 0;
}

Container::~Container()
{
	this->clear();

}

Container::Container(Container & rhs)
{
	for (int i = 0; i < rhs.getSize(); ++i)
	{
		this->putElementAtEnd(rhs.getElementsValueAt(i));
	}
}

void Container::putElementAtBegin(int valueToInsert)
{
	Element * toInsert = new Element;
	toInsert->e_value = valueToInsert;

	if (this->isEmpty())
	{
		toInsert->e_next = NULL;
		toInsert->e_previus = NULL;
		this->c_First = this->c_Last = toInsert;
		toInsert->e_number = c_size;
		c_size++;
	}
	else
	{
		Element * toCheck = new Element;
		toCheck = this->c_First;

		while (toCheck->e_next != NULL)
		{
			toCheck->e_number++;
			toCheck = toCheck->e_next;
		}

		this->c_First->e_previus = toInsert;
		toInsert->e_next = this->c_First;
		toInsert->e_previus = NULL;
		this->c_First = toInsert;
		toInsert->e_number = 0;
		c_size++;


	}
}

void Container::putElementAtEnd(int valueToInsert)
{
	Element * toInsert = new Element;
	toInsert->e_value = valueToInsert;

	if (this->isEmpty())
	{
		toInsert->e_next = NULL;
		toInsert->e_previus = NULL;
		this->c_First = this->c_Last = toInsert;
		toInsert->e_number = c_size;
		c_size++;
	}
	else
	{
		this->c_Last->e_next = toInsert;
		toInsert->e_previus = this->c_Last;
		toInsert->e_next = NULL;
		this->c_Last = toInsert;
		toInsert->e_number = c_size + 1;
		c_size++;
	}
}
int Container::getFirstElement()
{
	int valueToReturn = 0;

	if (this->isEmpty())
	{
		return 0;
	}
	else if (this->getSize() == 1)
	{
		valueToReturn = this->c_First->e_value;
		delete this->c_First;
		c_size--;
		return valueToReturn;
	}
	else
	{
		valueToReturn = this->c_First->e_value;
		this->c_First = this->c_First->e_next;
		delete this->c_First->e_previus;
		this->c_First->e_previus = NULL;
		c_size--;
		return valueToReturn;
	}

}

int Container::getLastElement()
{
	int valueToReturn = 0;

	if (this->isEmpty())
	{
		return 0;
	}
	else if (this->getSize() == 1)
	{
		valueToReturn = this->c_Last->e_value;
		delete this->c_Last;
		c_size--;
		return valueToReturn;
	}
	else
	{
		valueToReturn = this->c_Last->e_value;
		this->c_Last = this->c_Last->e_previus;
		delete this->c_Last->e_next;
		this->c_Last->e_next = NULL;
		c_size--;
		return valueToReturn;
	}
}




int Container::getElementsValueAt(int position)
{
	if (position == 0)
	{
		return this->c_First->e_value;
		this->c_First = this->c_First->e_next;

	}
	else if (position == this->getSize())
	{
		return this->c_Last->e_value;
	}
	else {


		Element * checker = this->c_First;
		for (int i = 0; i < position; ++i)
		{
			checker = checker->e_next;
		}

		return checker->e_value;
	}

}


Container & Container::operator=(Container & rhs)
{
	for (int i = 0; i < rhs.getSize(); ++i)
	{
		this->putElementAtEnd(rhs.getElementsValueAt(i));
	}

	return  *this;
}

bool Container::isEmpty()
{
	if (this->getSize() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Container::getSize()
{
	return c_size;
}

void Container::clear()
{
	while (this->isEmpty() == false)
	{
		this->getLastElement();
	}
}
