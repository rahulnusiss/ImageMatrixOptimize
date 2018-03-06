#include "Unordered.h"
#include <iostream>
#include <vector>
#include <map>
#include "Utils.h"
using namespace std;

Unordered::Unordered()
{
    //ctor
    m_util = new Utils();
}

Unordered::~Unordered()
{
    //dtor
    delete m_util;
}

void Unordered::setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq)                 
{
    m_matrix = iMatrix;
    m_seq = iSeq;
    // Row size from matrix size
    m_m = m_matrix.size();
    // Taking column size from first row.
    if (m_m > 0)
        m_n = m_matrix[0].size();
    else
        m_n = 0;

    m_seq_size = m_seq.size();

    // Display before sorting
    // m_util->displayMatrix(m_matrix);
    cout << "----------------------------------------------" << endl << endl;

    for (int i = 0; i < m_m; ++i){
        m_util->mergeSort(m_matrix[i], 0, m_n-1);
    }
    
    // Display after sorting
    // m_util->displayMatrix(m_matrix);
    
}

void Unordered::search()
{
    // To store all the rows with matching sequence
    vector<int> list_rows;

    for ( int i = 0; i < m_m; ++i)
    {
        if ( searchUnorderedSingleArray(m_matrix[i]))
        {
            list_rows.push_back(i);
        }

    }

    cout << "Number of rows: " << list_rows.size() << endl;
    // The rows with unordered sequence will be printed below
    for ( vector<int>::iterator it = list_rows.begin(); it != list_rows.end(); ++it)
    {
        cout << "Unordered present at row: " << *it << endl;
    }
}

bool Unordered::searchUnorderedSingleArray(const vector<int>& arr)
{
    // Get elements(key) , their counts(value) of sequence array
    map<int, int> count_map_seq;
    m_util->getCountMap( m_seq, m_seq_size, count_map_seq );
    // Get elements(key) , their counts(value) of ith row array from file
    //map<int, int> count_map_arr = getCountMap( arr, m_n );    
    bool exists = true;
    // for (int i = 0; i < m_seq_size ; ++i)
    map<int, int>::iterator it;
    for (it = count_map_seq.begin(); it != count_map_seq.end(); it++)    {   
        int element = it->first;
        // count of this element in row arr from 2D matrix.
        // int current_count = count_map_arr[element];                        
        int num_count = 0;
        int idx_low = m_util->lowerIndex(arr, 0, m_n-1, element, m_n);
        if ( -1 != idx_low )
        {
            // Number exist
            num_count = m_util->upperIndex(arr, 0, m_n-1, element, m_n) - idx_low + 1;
        }

        // Check for the total presence of the sequence array number in current row array of file.
        if ((it->second) > num_count)
        {
            exists = false;
            break;
        }
    }
    return exists;
}
