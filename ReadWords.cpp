using namespace std;

#include "ReadWords.h"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

ReadWords::ReadWords(const char *fname){
    //file handling method. open the file
	wordfile.open(fname);
    if (!wordfile){
		cout << "Failed to open " << fname << endl;
        exit(1);
    }
    wordfile >> nextword; // skip the WhiteSpace at start
    eoffound = false;
}

string removePunct(string word)
{
    //Get the length of the word provided
    int len = word.length();

    //Remove the punctuation at the start of the word.
    //Change len as the length of words then changes
    for (int i = 0; i < len; i++) {
        if(ispunct(word[i])) {
            word.erase(i--,1);
            len = word.length();
        }
        else
            //Break if we find a letter, as we allow punctuation in the middle of words.
            break;
    }
    //Remove punctuation, but in reverse
    len = word.length() - 1;
    for (int i = len; i >= 0; i--) {
        if (ispunct(word[i])) {
            word.erase(i, 1);
        }
        else
            break;
    }
    return word;
}

string ReadWords::getNextWord() {
    //Method used to return the next word, once it is processed through formatting
    word = removePunct(nextword); //Assign nextword to word, remove the punctuation
    transform(word.begin(), word.end(), word.begin(), ::tolower); //make it lower case
    wordfile >> nextword; //Move to the nextword
    return word;
}

bool ReadWords::isNextWord() {
    //Returns true whilst it is NOT at the end.
    //return !wordfile.eof();
      if (!wordfile.eof())
        eoffound = true;
      else
        eoffound = false;

    return eoffound;
}

void ReadWords::close() {
    //Close wordfile.
    if (wordfile.is_open())
        wordfile.close();
}

