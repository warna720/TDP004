#include <iostream>		// IOStream
#include <fstream> 		// Filestream
#include <sstream>		// Stringstream
#include <vector>		// Vector
#include <stdexcept>	// Exception Type


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

	istringstream ss{line};
	vector<int> vectorised;

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

bool checkRange(const vector<int>& trimino, const int& start, 
				const int& end)
{
	// Checks if trimino values is in range

	return ( start <= trimino.front() && 
			 trimino.back() <= end );
}

bool checkTriminoOrder(const vector<int>& trimino)
{
	// Checks if trimino order goes from smallest to largest

	return ( trimino.front() <= trimino.at(1) &&
			 trimino.at(1) <= trimino.back() );

}

bool checkTrimino(vector<int> trimino, const int& start, const int& end, 
				  const int unsigned& pass = 1)
{

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


bool isCorrect(const string& line, const int& start, const int& end)
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
			throw runtime_error("Something went really wrong...\nCant resume!");
		}
		else if ( cin.eof() )
		{
			cin.clear();
			cout << endl;
		}
		else if ( cin.fail() )
		{
			cerr << "\nWrong input. Input only integers." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}


void getRange(int& start, int& end)
{
	getInput("Choose the start number: ", start);
	getInput("Choose the end number: ", end, true, start);
}

void process(ifstream& ifs)
{
	int start;
	int end;
	getRange(start, end);

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
}

int main()
{
	ifstream ifs{"trimino3.txt"};
	
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
