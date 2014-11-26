#include <iostream>	// IOStream
#include <fstream> 	// Filestream
#include <random>	// Random generator

using namespace std;


// Pretty self explanatory code
// Commented what's not so obvious

void getIntInput(int & val, const string & message,
				 const bool & checkMin = false, const int & end = 0)
{
	cout << message;
	cin >> val;

	// if checkMin variable set to true then check if input <= minimum
	while(!cin || (checkMin && val <= end))
	{

		cout << "\nPlease behave..." << endl;
		cout << message;

		cin.clear();
		cin.ignore(1000, '\n');
		cin >> val;
	}
}

void getRows(int & rows)
{
	getIntInput(rows, "How many rows? ", true, 0);
}


void getRange(int & start, int & end)
{

	getIntInput(start, "Choose start number: ");
	getIntInput(end, "Choose end number: ", true, start);

}

int getRandomNumber(int const start, int const end)
{
	random_device rd;
	uniform_int_distribution<> uid(start, end);

	return uid(rd);
}

void randomNumbersToFile(ofstream & ofs)
{
	int rows;
	getRows(rows);

	int start;
	int end;
	getRange(start, end);

	for (; rows > 0; --rows)
	{
		ofs <<  getRandomNumber(start, end) << ' ' <<
				getRandomNumber(start, end) << ' ' <<
				getRandomNumber(start, end) << endl;
	}
}

int main()
{
	
	ofstream ofs("output.txt");
	if (ofs.is_open())
	{
		randomNumbersToFile(ofs);
	}


	return 0;
}
