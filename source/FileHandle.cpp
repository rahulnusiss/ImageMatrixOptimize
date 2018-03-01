#include "FileHandle.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

FileHandle::FileHandle()
{
	// For now hardcoded. Assumed within the same location as main.cpp
    m_path = "input.txt";
}

FileHandle::~FileHandle()
{
    //dtor
}

vector< vector<int> > FileHandle::loadFile()
{
	std::fstream myfile(m_path.c_str(), std::ios_base::in);
    string line;
    // 2D vector to load matrix
    vector< vector<int> > matrix;

    int a;
    //while (myfile >> a)
    while ( getline(myfile, line))
    {
        vector<int> vect;
        stringstream ss(line);
        // cout << line << endl;
        while (ss >> a)
        {
            vect.push_back(a);

            if (ss.peek() == ' ')
                ss.ignore();
        }
        matrix.push_back(vect);
    }

    int m = matrix.size();
    int n = matrix[0].size();
    cout << "Row: " << m << endl;
    cout << "Column: " << n << endl;
    for (int i = 0; i < m ; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix;
}
