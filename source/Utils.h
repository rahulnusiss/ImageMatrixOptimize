#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>
#include "ISearch.h"
using namespace std;
class Utils
{

public:

	/**
	* To merge left and right arrays for merge sort.
	*/
	void merge(vector<int>& arr, int l, int m, int r);

	/**
	* To implement merge sort on arr so that we could apply divide and conquer.
	*/
    void mergeSort(vector<int>& arr, int l, int h);

    /**
    * To display the matrix
    * iMatrix: Input 2D matrix
    */
    void displayMatrix(const vector< vector<int> >& iMatrix);

    /**
    * Divide and conquer algorithm to find highest index of number in array.
    * arr: Input arra in which we have to find lowest index.
    * low: minimum starting index
    * high: maximum end index
    * num: element to look for
    * size: size of arr
    */
    int upperIndex(const vector<int>& arr, int low, int high, int num, int size);

    /**
    * Divide and conquer algorithm to find lowest index of number in array.
    * arr: Input arra in which we have to find lowest index.
    * low: minimum starting index
    * high: maximum end index
    * num: element to look for
    * size: size of arr
    */
    int lowerIndex(const vector<int> & arr, int low, int high, int num, int size);

    /**
    * Function to return count of elements in arr as map. Used by algorithm 2 and 3.
    * arr: Input array to be processed into a map.
    * size: size of input array.
    * count_map: output a map with key as elements and value as their counts in arr.
    */
    void getCountMap( const vector<int>& arr, int size, map<int, int>& count_map);

};

#endif