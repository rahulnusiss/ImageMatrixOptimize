#ifndef BESTMATCH_H
#define BESTMATCH_H

#include <vector>
#include <map>
#include "ISearch.h"
#include "Utils.h"
using namespace std;
class BestMatch: public ISearch
{
    public:
        /**
        * Constructor
        */
        BestMatch();

        /**
        * Destructor
        */
        virtual ~BestMatch();

         /**
        * Set class attributes to be used for search
        * iMatrix: input 2D matrix
        * iSeq: input array from arguments on which search algorithm is applied
        */
        void setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq);

        /**
        * Search function implementation for sequence
        */

        void search();

    private:

        int getMatchArray(const vector<int>& arr, const map<int, int>& count_map_seq);


        // Attributes
        // Real matrix from file
        vector< vector<int> > m_matrix;        
        int m_m; // Rows
        int m_n; // Columns

        // Sequence array to be applied search
        vector<int> m_seq;
        // Size of seq array or vector
        int m_seq_size;

        // To get utilities
        Utils* m_util;

};

#endif 