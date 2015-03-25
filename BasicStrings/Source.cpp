#include <iostream> //standart i/o library
#include <vector>   //STL container
#include <fstream>  //file stream to read .dat files
#include <string>   //string structure
#include <algorithm>  //uses for sorting STL containers

using namespace std;  //standart namespace

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
	ifstream ifsWords ("words.dat", ios::in); //ifsWords asigned to "words.dat" for reading content in file
	while (!ifsWords.eof())                   //read .dat file until the end         
        {
		getline (ifsWords, tempString);   //read line from .dat file
		myTestString.append(" ");         //append " "(empty space after every line, in our case every word)        
		myTestString.append(tempString);  //formed word+" " appends to main string
	}

	vector< string > strVector;               //creates vector

	int stringSize;
	int positionLastINtervAl;
	string tempWord;

	while(!myTestString.size()==0)            //uses to cut every word from myTestString and put in the vector
	{
	    positionLastINtervAl = myTestString.find_last_of(" ");          //finds the position of last interval to mark the beggining the last word, works from back to the fron in myTestString
	    stringSize = myTestString.size();
	
	    tempWord = myTestString.substr(positionLastINtervAl+1, stringSize);
	    myTestString.erase(positionLastINtervAl);
	    strVector.push_back(tempWord);             //put the word in vector
	}

	

	
	vector< int > wordsCounterVector;          //creating vector witch will store the count fro every word

	sort(strVector.begin(), strVector.end());  //sort words vector
	
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
