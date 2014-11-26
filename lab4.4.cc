#include <fstream>		// Filestream

#include "words.h"


int main ()
{

	ifstream ifs("example.txt");
	vector<string> wordVector;

	Words w;

	if ( ifs.is_open() )
	{

		string word;

		while (ifs >> word)
		{
			w.addWord(word, wordVector);
		}
	}

	w.printWithLambda(wordVector);

	return 0;
}
