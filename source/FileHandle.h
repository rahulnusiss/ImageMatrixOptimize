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
    	
    	void encrypt();
    	void decrypt();
    	vector< vector<int> > loadFile();
    	void saveFile();
    private:
    	string m_path;
};

#endif // FILEHANDLE_H
