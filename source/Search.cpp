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

    // To test matrix
    // cout << "Row: " << m_m << endl;
    // cout << "Column: " << m_n << endl;
    // for (int i = 0; i < m_m ; ++i)
    // {
    //     for (int j = 0; j < m_n; ++j)
    //     {
    //         cout << m_matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

Search::~Search()
{
    //dtor
}

void Search::searchSequence()
{    
    vector<int> list_rows;

    for ( int i = 0; i < m_m; ++i)
    {
        if ( searchSequenceSingleArray(m_matrix[i]))
        {
            list_rows.push_back(i);
        }

    }

    cout << "Size: " << list_rows.size() << endl;
    // The rows with sequence will be printed below
    for ( vector<int>::iterator it = list_rows.begin(); it != list_rows.end(); ++it)
    {
        cout << *it << endl;
    }
}

bool Search::searchSequenceSingleArray(const vector<int>& arr)
{
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
        if ((m_n-index) < m_seq_size) { cout << "overflow" << endl; continue; }
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
        cout << " Row current index " << row_current_index << endl;
        if (flag_current)
        {
            //flag_seq = true;
            return true;
        }
    }
    return false;
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
    cout << "Best matching row: " << row << endl;

}

int Search::getMatchArray(const vector<int>& arr)
{
    // For repetetion
    map<int, int> count_map;
    for (int i = 0; i < m_seq_size; ++i)
    {
        if ( count_map.count(m_seq[i]) )
        {
            count_map[m_seq[i]] += 1;
        }
        else
        {
            count_map[m_seq[i]] = 1;
        }
    }

    cout << "  :::::: " << count_map[4] << endl;

    int matches = 0;
    //for (int i = 0; i < m_seq_size ; ++i)
    map<int, int>::iterator it;
    for (it = count_map.begin(); it != count_map.end(); it++)
    {
        int num_counts = 0;
        for( int j = 0; j < m_n; ++j)
        {
            if ( it->first == arr[j])
            {
                ++num_counts;
            }
        }
        // Which ever count is less is added to total matches
        (num_counts > it->second) ? (matches += it->second):(matches += num_counts);
    }

    cout << matches << endl;

    return matches;
}

void Search::searchUnordered()
{
    vector<int> list_rows;

    for ( int i = 0; i < m_m; ++i)
    {
        if ( searchUnorderedSingleArray(m_matrix[i]))
        {
            list_rows.push_back(i);
        }

    }

    cout << "Size: " << list_rows.size() << endl;
    // The rows with unordered sequence will be printed below
    for ( vector<int>::iterator it = list_rows.begin(); it != list_rows.end(); ++it)
    {
        cout << *it << endl;
    }
}

bool Search::searchUnorderedSingleArray(const vector<int>& arr)
{
    // For repetetion
    map<int, int> count_map;
    for (int i = 0; i < m_seq_size; ++i)
    {
        if ( count_map.count(m_seq[i]) )
        {
            count_map[m_seq[i]] += 1;
        }
        else
        {
            count_map[m_seq[i]] = 1;
        }
    }
    bool exists = true;
    for (int i = 0; i < m_seq_size ; ++i)
    {
        int current_count = 0;
        for( int j = 0; j < m_n; ++j)
        {
            if ( m_seq[i] == arr[j])
            {
                ++current_count;
            }
        }
        // Check for the total presence of the sequence array number in file matrix
        if (count_map[m_seq[i]] > current_count)
        {
            exists = false;
            break;
        }
    }

    return exists;
}