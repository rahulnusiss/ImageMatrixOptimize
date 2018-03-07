#include "Sequence.h"
#include <iostream>
#include <vector>
#include <map>
#include "Utils.h"
using namespace std;

Sequence::Sequence()
{
    //ctor
    m_util = new Utils();
}

void Sequence::setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq)                 
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

    // Display 2D matrix
    m_util->displayMatrix(m_matrix);
    
}

Sequence::~Sequence()
{
    //dtor
    delete m_util;
}

void Sequence::search()
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

bool Sequence::searchSequenceSingleArray(const vector<int>& arr)
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