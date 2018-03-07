#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <vector>
#include <map>
#include "ISearch.h"
#include "Utils.h"
using namespace std;
class Sequence: public ISearch
{
    public:
        /**
        * Constructor
        */
        Sequence();
        
        /**
        * Destructor
        */
        virtual ~Sequence();

        /**
        * To set the matrix
        * iMatrix: input 2D matrix
        * iSeq: input array from arguments on which search algorithm is applied
        */        
        void setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq);

        /**
        * Search function implementation for sequence
        */

        void search();

    private:

    	/**
        * Function to apply algorithm 1 on a single row from 2D matrix from file.
        * arr: Input array to be searched for sequence.
        * return: true if arr has the sequence, else false.
        */
        bool searchSequenceSingleArray(const vector<int>& arr);

        // Attributes
	    // Real matrix from file
	    vector< vector<int> > m_matrix;        
	    int m_m; // Rows
	    int m_n; // Columns

	    // Sequence array to be applied search
	    vector<int> m_seq;
	    // Size of seq array or vector
	    int m_seq_size;

	    // For utilities
	    Utils* m_util;

};

#endif 