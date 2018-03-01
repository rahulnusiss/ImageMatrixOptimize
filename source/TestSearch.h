#ifndef TESTSEARCH_H
#define TESTSEARCH_H

#include "Search.h"

class TestSearch
{
    public:
    	TestSearch();
        TestSearch(const Search& iSearch);
        virtual ~TestSearch();

        void testSequence();
        void testUnordered();
        void testBestMatch();    
    private:
    	Search m_search;
};

#endif // TESTSEARCH_H
