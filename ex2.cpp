
using namespace std;

#include "ReadWords.h"
#include "BarGraph.h"
#include <cctype>
#include <iostream>


main(){

    string fsearch; //used for string inputs. we cant input to a const char!
    string ofile; // string used for the outputfile
    string wfile; // string used for the word search file

    cout << "Please enter the filename to search" << endl;
    cin >> fsearch;
    cout << "Please enter the filename for wordsearch" << endl;
    cin >> wfile;
    cout << "Please enter the filename for output" << endl;
    cin >> ofile;

    const char* wsfile = wfile.c_str(); //convert our string to a const char
    const char* searchfile = fsearch.c_str();

    ReadWords reader = ReadWords(searchfile); //cretae an object and open a stream with the words that we wish to findv
    BarGraph barwrite = BarGraph(wsfile); //create an object open a stream to the bargraph word search file.


    while (reader.isNextWord() == true)
    {
        string foo = reader.getNextWord(); //go through the words in our searchfile and process them
		barwrite.CompareWord(foo); //perform a comparison and store results
    }

    string graph = barwrite.DrawGraph(); //draw our graph
    cout << graph; //output to cmd

    ofstream outfile (ofile);
    outfile << graph; //output to text
    outfile.close();


}


