#ifndef TESTSEARCH_H
#define TESTSEARCH_H

#include "Search.h"

class TestSearch
{
    public:
    	/**
    	* Constructor
    	*/
    	TestSearch();
    	/**
    	* Parameterised Constructor
    	* iSearch: Input search class object on which tests to be performed.
    	*/
        TestSearch(const Search& iSearch);
        /**
    	* Destructor
    	*/
        virtual ~TestSearch();

        /**
        * Function to test search type 1: Sequence search
        */
        void testSequence();

        /**
        * Function to test search type 2: Unordered search
        */
        void testUnordered();

        /**
        * Function to test search type 3: Best Match search
        */
        void testBestMatch();    

    private:
    	// Search object which has implementation of the three type of search
    	Search m_search;
};

#endif // TESTSEARCH_H
