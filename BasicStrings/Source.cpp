#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	
	int K = 0, P = 0;
	cout << "Enter your number K: ";
	cin >> K;
	cout << endl;
	cout << "Enter your number P: ";
	cin >> P;
	string myTestString;
	string tempString = " ";
	ifstream ifsWords ("words.dat", ios::in);
	while (!ifsWords.eof())
    {
		getline (ifsWords, tempString);
		myTestString.append(" ");
		myTestString.append(tempString);
	}

	vector< string > strVector;

	int stringSize;
	int positionLastINtervAl;
	string tempWord;

	while(!myTestString.size()==0)
	{
		positionLastINtervAl = myTestString.find_last_of(" ");
	    stringSize = myTestString.size();
	
	    tempWord = myTestString.substr(positionLastINtervAl+1, stringSize);
	    myTestString.erase(positionLastINtervAl);
	    strVector.push_back(tempWord);
	}

	

	
	vector< int > wordsCounterVector;

	sort(strVector.begin(), strVector.end());
	//unique(strVector.begin(), strVector.end());
	
	int primVectSize = 0;
	primVectSize = strVector.size();
	int wordsCounter = 0;

	for( int i=0; i<primVectSize; i++)
	{
		string chekWord = strVector.at(i);
		for (int j=0; j<primVectSize; j++)
		{
			if (chekWord == strVector.at(j))
			{
				wordsCounter++;
			}
		}
		wordsCounterVector.push_back(wordsCounter);
		wordsCounter = 0;
	}


	string wordForShow;
	int countForShow;

	for (int i=0; i<primVectSize; i++)
	{
		wordForShow = strVector.at(i);
		countForShow = wordsCounterVector.at(i);
		cout << "The word - " << wordForShow << " is " << countForShow << " times in your text!" << endl;
		
	}

	int letters = 0;

	cout << "Words, which symbols are greater than " << K << " :" << endl;
	for (int i=0; i<primVectSize; i++)
	{
		letters = strVector.at(i).length();
		if(letters > K)
		{
			cout << strVector.at(i) << endl;
		}
	}

	cout << "Words, which symbols are smaler than " << P << " :" << endl;
	for (int i=0; i<primVectSize; i++)
	{
		letters = strVector.at(i).length();
		if(letters < P)
		{
			cout << strVector.at(i) << endl;
		}
	}





	cout << endl;
	return 0;
}
