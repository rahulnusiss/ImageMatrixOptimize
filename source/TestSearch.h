#ifndef TESTSEARCH_H
#define TESTSEARCH_H

#include "ISearch.h"
#include <vector>
#include <map>
using namespace std;

typedef map<string, ISearch * > map_type;


class TestSearch
{
    public:
    	/**
    	* Constructor
    	*/
    	TestSearch();
    	
        /**
    	* Destructor
    	*/
        virtual ~TestSearch();

        /**
        * Actual function to test search type.
        * iSeq: Sequence matrix for searching
        * iStrArg: Search Type
        */
        void testSearch(const vector<int>& iSeq, const string& iStrArg);

        /**
        * To set the original matrix for test.
        * iMatrix: Input 2D matrix
        */

        void setMatrix(const vector< vector<int> >& iMatrix);

        /**
        * To perform benchmarking on randomn matrix values, repeatedly. Calculate average of all times.
        * iSeq: Input args sequence matrix
        * iStrArg: Search Type
        * iter: No. of iterations for benchmarking, default = 1000
        */

        void benchMark(const vector<int>& iSeq, const string& iStrArg, int iter = 1000);

    private:
    	// Search object which has implementation of the three type of search
    	ISearch* m_search;

        // To map search type with its object
        map_type m_search_type_map;
        // Original Matrix
        vector< vector<int> > m_original_matrix;
};

#endif // TESTSEARCH_H
