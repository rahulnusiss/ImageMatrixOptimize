#ifndef ISEARCH_H
#define ISEARCH_H

#include <vector>
using namespace std;
class ISearch
{
public:	      

    /**
    * Destructor
    */
    virtual ~ISearch() { }

    virtual void setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq) = 0;

	virtual void search() = 0;

private:
	
};

#endif