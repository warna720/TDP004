#include <iostream>		// IOStream
#include <fstream> 		// Filestream
#include <sstream>		// Stringstream
#include <vector>		// Vector
#include <stdexcept>	// Exception Type


using namespace std;


// It was hard to write so it should be hard to read...


void printTrimino(vector<int> const trimino)
{
	for (int unsigned x = 0; x < trimino.size(); ++x)
	{
		cout << trimino.at(x) << ' ';
	}
	cout << endl;
}


vector<int> getLineVectorised(string const line)
{
	//Returns a vectorised string with each char converted to an int

	istringstream ss(line);
	vector<int> vectorised;

	int num;

	while (ss >> num)
	{
		vectorised.push_back(num);
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

bool checkRange(vector<int> const& trimino, int const& start, int const& end)
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

bool checkTrimino(vector<int> trimino, int const& start, int const& end, int unsigned const& pass = 1)
{
	/*
	Sorry Litborn, your idea that we twist trimino until smallest value
	comes first did not work. 
	What happens if it's a trimino with 15 50 15?
	I doesn't twist because the smallest value is already first. :)

	And we felt that making this function recursive was
	simpler than to do more complicated tests.
	We could also do this with a simple loop.
	*/

	if (pass > trimino.size())
 	{
		return false;
	}

	else if( checkRange(trimino, start, end)  &&
			 checkTriminoOrder(trimino) )
	{
		return true;
	}

	twistTrimino(trimino);
	return checkTrimino(trimino, start, end, pass+1);
}


bool isCorrect(string const line, int start, int end)
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
		return checkTrimino(trimino, start, end);
	}
}


void getInput(string const& message, int & val,
              bool const& checkMin = false, int const& end = 0)
{

	bool valSet(false);

	while ( !(valSet) )
	{
		cout << message;

		//If incorrect input and
		//if checkMin variable set to true then check if input > minimum
		if ( cin >> val && (!checkMin || val > end))
		{
			valSet = true;
		}
		else if ( cin.bad() )
		{
			throw runtime_error("Something went really wrong...\n");
		}
		else if ( cin.eof() )
		{
			cin.clear();
			cout << endl;
		}
		else if ( cin.fail() )
		{
			cerr << "\nPlease behave!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}


void getRange(int & start, int & end)
{
	getInput("Choose the start number: ", start);
	getInput("Choose the end number: ", end, true, start);
}


int main()
{
	int start;
    int end;

	getRange(start, end);
	ifstream ifs("trimino3.txt");
	
	if(ifs.is_open())
	{
		string line;
		int lineNumber{1};

		while(getline(ifs, line))
		{
			if ( not(isCorrect(line, start, end)) )
			{
				cout << lineNumber << endl;
			}
			lineNumber++;
		}

		ifs.close();
	}

	return 0;
}
