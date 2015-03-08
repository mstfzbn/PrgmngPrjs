#include <iostream>
using namespace std;

void chekColum (int a[][3])
{
	int printArray[3] = {0,0,0};
	for (int j=0; j<3; j++)
	{
		for (int i=0; i<2; i++)
		{
			if (a[i][j] != i+j)
			{
				printArray[j] = 1;
			}
		}
	}

	for (int i=0; i<3; i++)
	{
		if (printArray[i] == 0)
		{
			cout << "In colum " << i+1 << " of your array, the formula aij=i+j is working!" << endl;
		}
	}

}

void averageCounter (double a[5])
{
	int elementsCount = 0;
	for (int i=1; i<4; i++)
	{
		if (a[i] == ((a[i-1]+a[i+1])/2))
		{
			elementsCount++;
		}
	}
	if (a[0] == (a[1]/2))
	{
		elementsCount++;
	}

	if (a[4] == (a[3]/2))
	{
		elementsCount++;
	}

	cout << "You have a " << elementsCount << " elements, who you will like :) " << endl;	

}



int main (){
	int myArray[2][3] = {{0,2,3},{1,5,6}};
	double dblArray[5] = {4, 8, 9, 10, 5};
	
	chekColum (myArray);
	averageCounter (dblArray);
	

	return 0;
}