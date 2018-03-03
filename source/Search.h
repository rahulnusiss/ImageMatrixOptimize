#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <map>
using namespace std;
class Search
{
    public:
        /**
        * Constructor
        */
        Search();
        /**
        * Parameterized Constructor
        * iMatrix: input 2D matrix
        * iSeq: input array from arguments on which search algorithm is applied
        */
        Search(const vector< vector<int> >& iMatrix, const vector<int>& iSeq);

        /**
        * Destructor
        */
        virtual ~Search();

        
        /**
        * Algorithm 1: The rows with sequence matching the cmd argument array        
        */
        void searchSequence();

        /**
        * Algorithm 2: The rows with unordered matching, i.e. the rows that contains all the required numbers.
        */
        void searchUnordered();
        
        /**
        * Algorithm 3: The row with the best match of sequence array. Prints the row with best match.
        * The printed row is the row with initial row index from 0.
        */
        void searchBestMatch();


        private:
        /**
        * Function to apply algorithm 1 on a single row from 2D matrix from file.
        * arr: Input array to be searched for sequence.
        * return: true if arr has the sequence, else false.
        */
        bool searchSequenceSingleArray(const vector<int>& arr);

        /**
        * Function to apply algorithm 2 on a single row from 2D matrix from file.
        * arr: Input array to be searched for all required numbers of sequence array.
        * return: true if arr has all the required numbers, else false.
        */
        bool searchUnorderedSingleArray(const vector<int>& arr);

        /**
        * Function to apply algorithm 3 on a single row from 2D matrix from file.
        * arr: Input array to be searched for number of match of sequence array.
        * return: true if arr has all the required numbers, else false.
        */
        int getMatchArray(const vector<int>& arr);
        
        /**
        * Function to return count of elements in arr as map. Used by algorithm 2 and 3.
        * arr: Input array to be processed into a map.
        * return: a map with key as elements and value as their counts in arr.
        */
        map<int, int> getCountMap( const vector<int>& arr, int size);

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
