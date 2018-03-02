#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <string>
#include <vector>
using namespace std;
class FileHandle
{
    public:
        FileHandle();
        virtual ~FileHandle();
    	
    	int encrypt( const int& data, const int& i, const int& j );
    	int decrypt( const int& data, const int& i, const int& j );
    	vector< vector<int> > loadFile();
    	void saveFile( const vector< vector<int> >& iMatrix );
    private:
    	string m_path;
};

#endif // FILEHANDLE_H
