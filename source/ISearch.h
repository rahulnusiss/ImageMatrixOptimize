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

    /**
    * To set the 2D and sequence matrix for the search function to be applied.
    */
    virtual void setMatrices(const vector< vector<int> >& iMatrix, const vector<int>& iSeq) = 0;

    /**
    * The search which will be performed.
    */
	virtual void search() = 0;

private:
	
};

#endif