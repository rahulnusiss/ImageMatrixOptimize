#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <string>
#include <vector>
using namespace std;
class FileHandle
{
    public:
        /**
        * Constructor
        */
        FileHandle();

        /**
        * Destructor
        */
        virtual ~FileHandle();
    	
        /**
        * Function to encrypt the data while saving the file.
        * data: the number to be encrypted
        * i : the position in row
        * j : the position in column
        * return : the encrypted number
        */
    	int encrypt( const int& data, const int& i, const int& j );

        /**
        * Function to decrypt the data while loading the file.
        * data: the number to be decrypted
        * i : the position in row
        * j : the position in column
        * return : the decrypted number
        */
    	int decrypt( const int& data, const int& i, const int& j );

        /**
        * Function to load the 2D matrix file from local.
        * return: The 2D matrix in dynamic array form as vector of vector.
        */
    	vector< vector<int> > loadFile();

        /**
        * Function to save the 2D matrix file to local.
        * iMatrix: The 2D matrix in dynamic array form as vector of vector.
        */
    	void saveFile( const vector< vector<int> >& iMatrix );

    private:
        // The path of file of 2D matrix.
    	string m_path;
};

#endif // FILEHANDLE_H
