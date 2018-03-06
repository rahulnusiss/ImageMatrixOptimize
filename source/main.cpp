#include "ISearch.h"
#include <iostream>
#include "TestSearch.h"
#include "FileHandle.h"
#include <chrono>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    // Sequence array: The input array from the argument. It is the array from the argument.
    // I call it as sequence array in my code even if the array given is for other two search.

    // Note: The answer value of row returned is from index 0.

    // Input argument has 2 parts. First the type of search. second the array.    
    cout << argv[argc-1] << endl;

    string delimiter = " ";
    string searchArgs = argv[argc-1];

    // Taking the first part of args denoting the type of search
    std::string searchType = searchArgs.substr(0, searchArgs.find(delimiter));
    cout << "SearchType : " << searchType << endl;

    // Taking the string with numbers separated by space only. Removing the first part.
    searchArgs = searchArgs.substr(searchArgs.find(delimiter)+1, searchArgs.length());
    cout << "SearchArgs : " << searchArgs << endl;    

    int a = 0;
    vector<int> sequence;
    stringstream ss(searchArgs);
    // cout << line << endl;
    while (ss >> a)
    {
        sequence.push_back(a);

        if (ss.peek() == ' ')
            ss.ignore();
    }    

	 vector< vector<int> > matrix;    
     FileHandle filehandler;
     matrix = filehandler.loadFile();
    
     TestSearch testObj;
     testObj.setMatrix(matrix);

     //std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now() ;
     testObj.benchMark(sequence, searchType, 1000);
     //testObj.testSearch(sequence, searchType);
    return 0;
}