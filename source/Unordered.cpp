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

    m_size_1D = m_m*m_n;    

    // Display before sorting
    //m_util->displayMatrix(m_matrix);
    //cout << "----------------------------------------------" << endl;

    for (int i = 0; i < m_m; ++i){
        m_util->mergeSort(m_matrix[i], 0, m_n-1);
    }

    for (int i = 0; i < m_m; ++i)
    {
        for (int j =0; j < m_n; ++j)
        {
            m_matrix_1D.push_back(m_matrix[i][j]);    
        }        
    }

    // Display 1D matrix
    for (long int i = 0; i < m_size_1D; ++i)
    {
        cout << m_matrix_1D[i] << " ";
        if((i+1)%m_n == 0){
            cout << endl;
        }
    }
    
    // Display after sorting
    // m_util->displayMatrix(m_matrix);
    
}

void Unordered::search()
{
    // To store all the rows with matching sequence
    vector<int> list_rows;

    map<int, int> count_map_seq;
    m_util->getCountMap( m_seq, m_seq_size, count_map_seq );
    int first = 0;
    int last = -1;

    for ( int i = 0; i < m_m; ++i)
    {
        first = last+1;
        last = (i+1)*m_n - 1 ;
        //cout << "First: " << first;
        //cout << "  Last: " << last << endl;
        if ( searchUnorderedSingleArray(count_map_seq, first, last) )
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

bool Unordered::searchUnorderedSingleArray(const map<int, int>& count_map_seq, const int& first, const int& last)
{
    // Get elements(key) , their counts(value) of sequence array    
    // Get elements(key) , their counts(value) of ith row array from file
    //map<int, int> count_map_arr = getCountMap( arr, m_n );    
    bool exists = true;
    // for (int i = 0; i < m_seq_size ; ++i)
    map<int, int>::const_iterator it;
    for (it = count_map_seq.begin(); it != count_map_seq.end(); it++)    
    {   
        int element = it->first;
        // count of this element in row arr from 2D matrix.
        // int current_count = count_map_arr[element];                        
        int num_count = 0;
        int idx_low = m_util->lowerIndex(m_matrix_1D, first, last, element, first);
        if ( -1 != idx_low )
        {
            // Number exist
            num_count = m_util->upperIndex(m_matrix_1D, first, last, element, last+1) - idx_low + 1;
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
