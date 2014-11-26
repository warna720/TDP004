#include <iostream>	// IOStream
#include <fstream> 	// Filestream
#include <vector>	// Vector

using namespace std;

// It was hard to write so it should be hard to read...

void printTrimino(vector<int> trimino)
{
	for (int unsigned x = 0; x < trimino.size(); ++x)
	{
		cout << trimino.at(x);
	}
	cout << endl;
}

vector<int> getLineVectorised(string const line)
{
	//Returns a vectorised string with each char converted to an int

	vector<int> vectorised;

	for (int unsigned x = 0; x <= 2; ++x)
	{
		vectorised.push_back(line[x] - '1' + 1);
	}
	
	return vectorised;
}

void twistTrimino(vector<int> & trimino)
{
	//Twists the trimino by pushing back the 
	//first value and then deleting the first value

	trimino.push_back(trimino.front());
	trimino.erase(trimino.begin());
}

bool correctSize(vector<int> const trimino)
{
	// Check if three (trimino size) integers given

	return trimino.size() == 3;
}

bool checkRange(vector<int> const& trimino, int const& start = 0, int const& end = 5)
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

bool checkTrimino(vector<int> trimino, int unsigned const& pass = 1)
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

bool isCorrect(string const line)
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


int main()
{
	ifstream ifs("trimino1.txt");
	
	if(ifs.is_open())
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

		ifs.close();
	}

	return 0;
}
