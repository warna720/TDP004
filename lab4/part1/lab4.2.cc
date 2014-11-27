#include <iostream>	// IOStream
#include <fstream> 	// Filestream
#include <sstream>	// Stringstream
#include <vector>	// Vector

using namespace std;

// It was hard to write so it should be hard to read...

void printTrimino(const vector<int>& trimino)
{
	for (int unsigned x = 0; x < trimino.size(); ++x)
	{
		cout << trimino.at(x) << ' ';
	}
	cout << endl;
}

vector<int> getLineVectorised(const string& line)
{
	//Returns a vectorised string with each char converted to an int

	vector<int> vectorised;
	istringstream ss{line};

	int num;

	while (ss >> num)
	{
		vectorised.push_back(num);
	}
	
	return vectorised;
}

void twistTrimino(vector<int>& trimino)
{
	//Twists the trimino by pushing back the 
	//first value and then deleting the first value

	trimino.push_back(trimino.front());
	trimino.erase(trimino.begin());
}

bool correctSize(const vector<int>& trimino)
{
	// Check if three (trimino size) integers given

	return trimino.size() == 3;
}

bool checkRange(const vector<int>& trimino, const int& start = -100, 
				const int& end = 100)
{
	// Checks if trimino values is in range

	return ( start <= trimino.front() && 
			 trimino.back() <= end );
}

bool checkTriminoOrder(vector<int> const& trimino)
{
	// Checks if trimino order goes from smallest to largest

	return ( trimino.front() <= trimino.at(1) &&
			 trimino.at(1) <= trimino.back() );

}

bool checkTrimino(vector<int>& trimino, const unsigned int& pass = 1)
{

	if (pass > trimino.size())
 	{
		return false;
	}

	else if( checkRange(trimino)  &&
			 checkTriminoOrder(trimino) )
	{
		return true;
	}

	twistTrimino(trimino);

	return checkTrimino(trimino, pass+1);
}

bool isCorrect(const string& line)
{
	vector<int> trimino = getLineVectorised(line);

	// First make a breif check of size
	// If passed the size limit, make more checks
	if ( !(correctSize(trimino)) )
	{
		return false;
	}
	else
	{
		return checkTrimino(trimino);
	}
}

void process(ifstream& ifs)
{
	string line;
	int lineNumber{1};

	while(getline(ifs, line))
	{
		if ( not(isCorrect(line)) )
		{
			cout << lineNumber << endl;
		}
		lineNumber++;
	}
}

int main()
{
	ifstream ifs("trimino2.txt");
	
	if(ifs.is_open())
	{
		process(ifs);

		ifs.close();
	}
	else
	{
		cerr << "Error: Could not open file." << endl;
	}

	return 0;
}
