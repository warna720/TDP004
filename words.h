#ifndef WORDS_H
#define WORDS_H

// Did not compile without including this in header
// Even if we include them in word.cc
#include <map>
#include <vector>

using namespace std;

class Words
{

public:
	bool addWord(string word, map<string, int> & cl);
	bool addWord(string word, vector<string> & wordVector);

	void printCleanList(const map<string, int> & cl);			//Labb1
	void printOrderedCleanList(const map<string, int> & cl);	//Labb2
	void printLongLine(const vector<string> wordVector);				//Labb3
	void printWithLambda(vector<string> wordVector);			//Labb4

private:
	map<int, string> mapIntString(const map<string, int> & cl);

	bool hyphenNotOutside(const string & word);
	bool onlyAlphaAndHyphen(const string & word);
	bool isClean(const string & word);
	void filterDelete(string & word);
	bool isCorrect(string & word);

	void toLower(string & word);
	bool is_in_string(const string & word, const string & c);

};

#endif
