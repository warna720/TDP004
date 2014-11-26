#include <fstream>		// Filestream

#include "words.h"

using namespace std;

int main ()
{

	ifstream ifs("example.txt");
	map<string, int> cleanList;

	Words w;

	if ( ifs.is_open() )
	{

		string word;

		while (ifs >> word)
		{
			w.addWord(word, cleanList);
		}
	}

	w.printCleanList(cleanList);

	return 0;
}
