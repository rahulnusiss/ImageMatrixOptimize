#include "TestSearch.h"
#include "Search.h"
#include <iostream>
using namespace std;

TestSearch::TestSearch()
{
    //ctor
}

TestSearch::TestSearch(const Search& iSearch)
{
    m_search = iSearch;
}

TestSearch::~TestSearch()
{
    //dtor
}

void TestSearch::testSequence()
{
	cout << "====================Start Test Sequence=====================" << endl;
	//int matrix[4][7] = {{1,2,10,3,4,8,9}, {3,4,5,6,9,10,11}, {41,31,41,31,41,3,4}, {5,3,4,8,9,6,7}};
    // int seq[4] = {3,4,8,9};
    int seq[2] = {3,5};
    m_search.searchSequence(seq,2);
    cout << "====================End Test Sequence=====================" << endl;
}

void TestSearch::testUnordered()
{
	cout << "====================Start Test Unordered=====================" << endl;
	//int matrix[4][7] = {{1,4,10,3,4,8,4}, {3,4,4,6,9,8,11}, {9,4,4,4,4,3,4}, {5,8,4,4,4,4,7}};
    //int seq[4] = {3,4,4,4};
    int seq[2] = {3,5};
    m_search.searchUnordered(seq,2);
    cout << "====================End Test Unordered=====================" << endl;
}

void TestSearch::testBestMatch()
{
	cout << "====================Start Test Best match=====================" << endl;
	//int matrix[4][7] = {{1,4,10,3,4,8,4}, {3,4,4,6,9,8,11}, {9,4,4,4,9,3,4}, {5,8,4,4,4,4,7}};
    int seq[6] = {3,4,4,4,11,7};
    m_search.searchBestMatch(seq,6);
    cout << "====================End Test Best match=====================" << endl;
}