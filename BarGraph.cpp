using namespace std;

#include "BarGraph.h"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <map>

BarGraph::BarGraph(const char* fname)
{
    //File handler used
    searchfile.open(fname);
    if (!searchfile) {
        cout << "Failed to open " << fname << endl;
        exit(1);
    }

    bool reading = true;
    //This method reads the SearchWord file, and places the words into a vector
    while (reading) {
        if (!searchfile.eof()) {
			searchfile >> nextword;

			//only add the word if its not already in the map... adding it twice can cause issues!
			if (!wordmap[nextword]){
				wordmap[nextword]++;
				}
        }
        else {
            reading = false;
        }
    }
}

void BarGraph::CompareWord(string word)
{
    //iterate through the map, and compare the word parameter. if it matches increment map
    for(map <string, int>::iterator it = wordmap.begin(); it != wordmap.end(); it++) {
        if (!word.compare(it->first)) {
            wordmap[it->first]++;
        }
    }
}

string BarGraph::DrawGraph()
{
    //the word, along with the key is printed. also print a graph given a key.
    for(map <string, int>::iterator it = wordmap.begin(); it != wordmap.end(); it++) {
        //this could be made into a single line, but this is more readable...
        graphresults += it->first + " ";
        graphresults += DrawStars(it->second-1) + " "; //draw the chart
        graphresults += to_string(it->second-1) + "\n";
    }
    return graphresults;
}

string BarGraph::DrawStars(int num)
{
    //clear stars
    string stars = "";
    int gcd = 0;
    //find the GCD
    if (num<2){
            starnum = num;
            }
    else{
        for (int i=1; i<=num/2;i++)
        {
            if (num%i==0)
                {
                    gcd = i;
                }
        }
        //divide n by gcd to find scales
        starnum = (num/gcd);
    }
    //loop to print stars
    for(int i = 1; i<=starnum; i++)
    {
        stars += "*";
    }
    //return str
    stars += " with a scale of " + to_string(gcd) + ". Total found:";
    return stars;
}



