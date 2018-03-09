#include "BestMatch.h"
#include <iostream>
#include <vector>
#include <map>
#include "Utils.h"
using namespace std;

BestMatch::BestMatch()
{
    //ctor
    m_util = new Utils();
}

BestMatch::~BestMatch()
{
    //dtor
    delete m_util;
}

void BestMatch::setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq)                 
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
    m_util->displayMatrix(m_matrix);
    // cout << "----------------------------------------------" << endl << endl;

    for (int i = 0; i < m_m; ++i){
        m_util->mergeSort(m_matrix[i], 0, m_n-1);
    }
    
    // Display after sorting
    // m_util->displayMatrix(m_matrix);
    
}

void BestMatch::search()
{
    map<int, int> count_map_seq; 
    m_util->getCountMap(m_seq, m_seq_size, count_map_seq);

    int bestMatch = 0;
    int row = -1;
    for ( int i = 0; i < m_m; ++i)
    {
        int current_match = getMatchArray(m_matrix[i], count_map_seq);
        if ( bestMatch < current_match)
        {
            bestMatch = current_match;
            row = i;
            // The best match could be of maximum value of sequence matrix size
            if ( bestMatch == m_seq_size)
            {
                break;
            }
        }
    }

    // The row with closest match will be printed below
    cout << "Best matching row: " << row << " with match " << bestMatch << endl;

}

int BestMatch::getMatchArray(const vector<int>& arr, const map<int, int>& count_map_seq)
{    
    //map<int, int> count_map_arr = getCountMap( arr, m_n);

    int matches = 0;
    //for (int i = 0; i < m_seq_size ; ++i)
    map<int, int>::const_iterator it;
    for (it = count_map_seq.begin(); it != count_map_seq.end(); it++)
    {
        
        int element = it->first;
        //int num_counts = count_map_arr[element];    
        int num_counts = 0;

        int idx_low = m_util->lowerIndex(arr, 0, m_n-1, element, m_n);
        if ( -1 != idx_low )
        {
            // Number exist
            num_counts = m_util->upperIndex(arr, 0, m_n-1, element, m_n) - idx_low + 1;
        }        
        // Which ever count is less is added to total matches
        (num_counts > it->second) ? (matches += it->second):(matches += num_counts);
    }

    cout << "Match density: " << matches << endl;

    return matches;
}