#include <iostream>		// IO Stream
#include <iomanip>		// setw();
#include <map>			// Map to the gold
#include <algorithm>	// transform function
#include <vector>

#include "words.h"

using namespace std;


void Words::printCleanList(const map<string, int> & cl)
{
	for (map<string, int>::const_iterator it = cl.cbegin();
		 it != cl.cend(); ++it)
	{
		cout << setw(25) << it->first << " : " << it->second << endl;
	}
}

map<int, string> Words::mapIntString(const map<string, int> & cl)
{
	map<int, string> m;

	for (map<string, int>::const_iterator it = cl.cbegin();
		 it != cl.cend(); ++it)
	{
		m[it->second] = it->first;
	}

	return m;
}

void Words::printOrderedCleanList(const map<string, int> & cl)
{
	map<int, string> ordered = mapIntString(cl);
	
	for (map<int, string>::const_reverse_iterator it = ordered.crbegin();
		 it != ordered.crend(); ++it)
	{
		for (map<string, int>::const_iterator sit = cl.cbegin();
			 sit != cl.cend(); ++sit)
		{
			if (it->first == sit->second)
			{
				cout << setw(25) << sit->first << " : " << sit->second << endl;
			}
		}
	}
}

void Words::printLongLine(const vector<string> wordVector)
{
	for_each(wordVector.begin(), wordVector.end(), [] (const string & word)
	{
		cout << word << " ";
	});
}

void Words::printWithLambda(vector<string> wordVector)
{
	int lengthCounter{0};
	for_each(wordVector.begin(), wordVector.end(), [&lengthCounter] (const string & word)
	{
		if (lengthCounter != 0 && lengthCounter + word.length() > 40)
		{
			cout << endl;
			lengthCounter = 0;
		}
		lengthCounter += word.length() + 1;
		cout << word << " ";
	});
	cout << endl;
}

bool Words::hyphenNotOutside(const string & word)
{
	return word[0] != '-' && word[word.length()-1] != '-';
}

bool Words::is_in_string(const string & word, const string & c)
{
	return word.find(c) != string::npos;
}

bool Words::onlyAlphaAndHyphen(const string & word)
{
	//Checks if chars is alpha with exception for '-'

	for (string::const_iterator it = word.cbegin(); it != word.cend(); ++it)
	{
		if ( !(isalpha(*it)) && *it != '-')
		{
			return false;
		}
	}
	return true;
}

bool Words::isClean(const string & word)
{
	return onlyAlphaAndHyphen(word) && !is_in_string(word, "--") && hyphenNotOutside(word);
}

void Words::filterDelete(string & word)
{
	// Checks every char in filter
    
	while (word.length() > 0 && (word.front() == '"' || word.front() == '('))
    {
        word.erase(word.begin());
    }

    while (word.length() > 0 && 
        (word.back() == '!' ||
	     word.back() == '?' ||
    	 word.back() == ';' ||
	     word.back() == ',' ||
    	 word.back() == ':' ||
    	 word.back() == '.' ||
    	 word.back() == ')' ||
    	 word.back() == '"' ||
    	 word.back() == '\''))
    {
        word.pop_back();
    }

    if (word.length() > 1 && word[word.length()-2] == '\'' && word.back() == 's')
    {
        word.pop_back();
        word.pop_back();
    }
}

bool Words::isCorrect(string & word)
{
	filterDelete(word);

	return word.length() > 2 && isClean(word);

}

void Words::toLower(string & word)
{
	// A bit of google and stackoverflow
	// Then, MAGIQUE
	transform(word.begin(), word.end(), word.begin(), ::tolower);
}

bool Words::addWord(string word, vector<string> & wordVector)
{
	//toLower(word);

	if ( isCorrect(word) )
	{
		wordVector.push_back(word);
		return true;
	}

	return false;
}

bool Words::addWord(string word, map<string, int> & cl)
{
	toLower(word);

	if ( isCorrect(word) )
	{
		++cl[word];
		return true;
	}

	return false;
}

