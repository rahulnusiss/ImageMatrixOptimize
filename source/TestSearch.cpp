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
    m_search.searchSequence();
    cout << "====================End Test Sequence=====================" << endl;
}

void TestSearch::testUnordered()
{
	cout << "====================Start Test Unordered=====================" << endl;	
    m_search.searchUnordered();
    cout << "====================End Test Unordered=====================" << endl;
}

void TestSearch::testBestMatch()
{
	cout << "====================Start Test Best match=====================" << endl;	
    m_search.searchBestMatch();
    cout << "====================End Test Best match=====================" << endl;
}