#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
using namespace std;
class Search
{
    public:
        Search();
        Search(const vector< vector<int> >& iMatrix);
        virtual ~Search();
        // Part 1: The rows with sequence
        void searchSequence( int seq[], int seq_size );

        // Part 2: Rows with unordered sequence
        void searchUnordered( int seq[], int seq_size);

        // Part 3: Rows with closest match
        void searchBestMatch( int seq[], int seq_size);
        private:
        bool searchSequenceSingleArray(const vector<int>& arr, int n, int seq[], int seq_size);
        bool searchUnorderedSingleArray(const vector<int>& arr, int n, int seq[], int seq_size);
        int getMatchArray(const vector<int>& arr, int n, int seq[], int seq_size);

        // Attributes
        vector< vector<int> > m_matrix;
        int m_m; // Rows
        int m_n; // Columns
  };

#endif // SEARCH_H
