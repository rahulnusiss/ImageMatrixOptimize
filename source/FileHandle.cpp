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
	fstream myfile(m_path.c_str(), std::ios_base::in);
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

void FileHandle::saveFile(const vector< vector<int> >& iMatrix)
{
    // vector< vector<int> > matrix = loadFile();
    int m = iMatrix.size();
    int n = 0;
    if (m > 0) { n = iMatrix[0].size(); }
        
    // open the file (meaning "output file stream")
    ofstream output("output_encrypt.txt"); 
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            int num = encrypt(iMatrix[i][j], i, j);
            // Like cout stream to file
            output << num << " ";
        }
        output << "\n";
    } 
}

int FileHandle::encrypt(const int& data, const int& i, const int& j)
{
    // If (i+j) = even, then addd the number by 2
    if ( (i+j)%2 == 0)
    {
        return (data+2);
    }
    // If i+j = odd, then add the number by 3
    return (data+3);
}

// Reverse the encryption logic
int FileHandle::decrypt(const int& data, const int& i, const int& j)
{
    // If (i+j) = even, then subtract the number by 2
    if ( (i+j)%2 == 0)
    {
        return (data-2);
    }
    // If i+j = odd, then subtract the number by 3
    return (data-3);
}