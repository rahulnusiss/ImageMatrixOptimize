#include "Search.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

Search::Search()
{
    //ctor
}

Search::Search(const vector< vector<int> >& iMatrix, const vector<int>& iSeq):
                 m_matrix(iMatrix),
                 m_seq(iSeq)
{
    // Row size from matrix size
    m_m = m_matrix.size();
    // Taking column size from first row.
    if (m_m > 0)
        m_n = m_matrix[0].size();
    else
        m_n = 0;

    m_seq_size = m_seq.size();
    
}

Search::~Search()
{
    //dtor
}

void Search::searchSequence()
{   
    // To store all the rows with matching sequence
    vector<int> list_rows;

    for ( int i = 0; i < m_m; ++i)
    {
        if ( searchSequenceSingleArray(m_matrix[i]))
        {
            list_rows.push_back(i);
        }

    }

    cout << "Number of rows with sequence: " << list_rows.size() << endl;
    // The rows with sequence will be printed below
    for ( vector<int>::iterator it = list_rows.begin(); it != list_rows.end(); ++it)
    {
        cout << "Sequence present at row: " << *it << endl;
    }
}

bool Search::searchSequenceSingleArray(const vector<int>& arr)
{
    // To store position of appearence of m_seq[0] in arr.
    vector<int> index_vec;
    for (int j = 0; j < m_n; ++j)
        {
            if ( arr[j] == m_seq[0])
            {
                index_vec.push_back(j);
                //cout << j << " Value: " << arr[j] << endl;
            }
        }

    for ( vector<int>::iterator it = index_vec.begin(); it != index_vec.end(); ++it)
    {
        int index = *it;
        // if sequence matrix overflows the current matrix then skip
        if ((m_n-index) < m_seq_size) { /*cout << "overflow" << endl;*/ continue; }
        //cout << " Index " << index << endl;
        bool flag_current = true;
        int row_current_index = 0;
        int j = 0;
        for (j = index; j < m_n ; ++j )
        {
            row_current_index = j-index;
            if ( m_seq_size <= row_current_index)
            {
                break;
            }
            else{
                if (arr[j] != m_seq[row_current_index])
                {
                    //cout << "j-index: " << row_current_index << "--" << m_seq[row_current_index] << " Check contains " << arr[j] << endl;
                    flag_current = false;
                    break;
                }
            }
        }
        // cout << " Row current index " << row_current_index << endl;
        if (flag_current)
        {            
            return true;
        }
    }
    return false;
}

void Search::searchUnordered()
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

bool Search::searchUnorderedSingleArray(const vector<int>& arr)
{
    // Get elements(key) , their counts(value) of sequence array
    map<int, int> count_map_seq = getCountMap( m_seq, m_seq_size );
    // Get elements(key) , their counts(value) of ith row array from file
    map<int, int> count_map_arr = getCountMap( arr, m_n );    
    bool exists = true;
    // for (int i = 0; i < m_seq_size ; ++i)
    map<int, int>::iterator it;
    for (it = count_map_seq.begin(); it != count_map_seq.end(); it++)    {   
        int element = it->first;
        // count of this element in row arr from 2D matrix.
        int current_count = count_map_arr[element];                        
        // Check for the total presence of the sequence array number in current row array of file.
        if ((it->second) > current_count)
        {
            exists = false;
            break;
        }
    }
    return exists;
}

void Search::searchBestMatch()
{

    int bestMatch = 0;
    int row = -1;
    for ( int i = 0; i < m_m; ++i)
    {
        int current_match = getMatchArray(m_matrix[i]);
        if ( bestMatch < current_match)
        {
            bestMatch = current_match;
            row = i;
        }
    }

    // The row with closest match will be printed below
    cout << "Best matching row: " << row << " with match " << bestMatch << endl;

}

int Search::getMatchArray(const vector<int>& arr)
{    
    map<int, int> count_map_seq = getCountMap(m_seq, m_seq_size);
    map<int, int> count_map_arr = getCountMap( arr, m_n);

    int matches = 0;
    //for (int i = 0; i < m_seq_size ; ++i)
    map<int, int>::iterator it;
    for (it = count_map_seq.begin(); it != count_map_seq.end(); it++)
    {
        
        int element = it->first;
        int num_counts = count_map_arr[element];    
        // Which ever count is less is added to total matches
        (num_counts > it->second) ? (matches += it->second):(matches += num_counts);
    }

    cout << "Match density: " << matches << endl;

    return matches;
}

// Returns a map with key as elements and value as their counts in arr.
map<int, int> Search::getCountMap( const vector<int>& arr, int size)
{
    map<int, int> count_map;
    for (int i = 0; i < size; ++i)
    {
        if ( count_map.count(arr[i]) )
        {
            count_map[arr[i]] += 1;
        }
        else
        {
            count_map[arr[i]] = 1;
        }
    }
    return count_map;
}