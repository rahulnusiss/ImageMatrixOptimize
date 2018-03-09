#ifndef UNORDERED_H
#define UNORDERED_H

#include <vector>
#include <map>
#include "ISearch.h"
#include "Utils.h"
using namespace std;
class Unordered: public ISearch
{
    public:
        /**
        * Constructor
        */
        Unordered();        

        /**
        * Destructor
        */
        virtual ~Unordered();

        /**
        * To set the 2D matrix
        * iMatrix: input 2D matrix
        * iSeq: input array from arguments on which search algorithm is applied
        */        
        void setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq);

        /**
        * Search function implementation for Unordered
        */
        void search();

    private:
        /**
        * Function to apply algorithm 2 on a single row from 2D matrix from file.
        * 
        */
        bool searchUnorderedSingleArray(const map<int, int>& count_map_seq, const int& first, const int& last);

        

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

        // Single matrix
        vector<int> m_matrix_1D;
        long int m_size_1D;

};

#endif 