/**
 * ReadWords Interface for Assignment 1
 */

#ifndef BARGRAPH_H
#define BARGRAPH_H
/**
 * Bargraph class.
 * Loads searchable words and creates a bargraph
 */
using namespace std;

#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <map>

 class BarGraph
 {
   public:

     //constructor
     BarGraph(const char *filename);
     //used to compare the words loaded from searchword and readwords
     void CompareWord(string word);
     //returns the graph string
     string DrawGraph();
     //draws the table for printing
     string DrawStars(int num);
     //map used to count the found words
     map<string, int> wordmap;


   private:
     //used to open the file
     ifstream searchfile;
     //used to read words from the searchfile
     string nextword;
     //used to return the graph
     string graphresults;
     //used to store stars
     string stars;
     //used for a counter
     int starnum;

 };

 #endif
