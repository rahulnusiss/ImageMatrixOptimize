#include "Search.h"
#include "TestSearch.h"
#include "FileHandle.h"
#include <vector>
using namespace std;

// g++ main.cpp Search.cpp Search.h
int main()
{
	vector< vector<int> > matrix;
    //Search obj;
    FileHandle filehandler;
    matrix = filehandler.loadFile();
    Search obj2(matrix);
    TestSearch testObj(obj2);
    testObj.testSequence();
    testObj.testUnordered();
    testObj.testBestMatch();
    return 0;
}