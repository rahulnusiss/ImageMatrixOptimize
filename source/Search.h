#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
using namespace std;
class Search
{
    public:
        Search();
        Search(const vector< vector<int> >& iMatrix, const vector<int>& iSeq);
        virtual ~Search();
        // Part 1: The rows with sequence
        void searchSequence();

        // Part 2: Rows with unordered sequence
        void searchUnordered();

        // Part 3: Rows with closest match
        void searchBestMatch();


        private:
        bool searchSequenceSingleArray(const vector<int>& arr);
        bool searchUnorderedSingleArray(const vector<int>& arr);
        int getMatchArray(const vector<int>& arr);

        // Attributes

        // Real matrix from file
        vector< vector<int> > m_matrix;        
        int m_m; // Rows
        int m_n; // Columns

        // Sequence array to be applied search
        vector<int> m_seq;
        // Size of seq array or vector
        int m_seq_size;
  };

#endif // SEARCH_H
