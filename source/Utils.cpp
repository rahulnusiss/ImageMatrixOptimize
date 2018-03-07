#include "Unordered.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void Utils::displayMatrix(const vector< vector<int> >& iMatrix){
    int rows = iMatrix.size();
    int cols = 0;
    if ( rows > 0 ){
        cols = iMatrix[0].size();
    }

    for (int i = 0; i < rows; ++i){
        for (int j =0; j < cols; ++j){
            cout << iMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Returns a map with key as elements and value as their counts in arr.
void Utils::getCountMap( const vector<int>& arr,const int& size, map<int, int>& count_map)
{
    // map<int, int> count_map;
    for (int i = 0; i < size; ++i)
    {
        if ( count_map.count(arr[i]) )
        {
            count_map[arr[i]] += 1;
        }
        else
        {
            count_map[arr[i]] = 1;
        }
    }
   // return count_map;
}

void Utils::merge(vector<int>& arr, int l, int m, int r){
    int i, j, k;
    int size1 = m - l + 1;
    int size2 =  r - m;
 
    // Temporary left and right array
    int L[size1] = {0}, R[size2] = {0};
 
    // Data to be copied in temp arrays
    for (i = 0; i < size1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < size2; j++)
        R[j] = arr[m + 1+ j];
 
    // Merge in arr[l].... to..arr[r]
    // Initial indices
    i = 0;
    j = 0;
    k = l;
    while (i < size1 && j < size2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Merging remaining values

    // Left
    while (i < size1)
    {
        arr[k] = L[i];
        i++;
        k++;
    } 
    
    // Right
    while (j < size2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Utils::mergeSort(vector<int>& arr, int low, int high){
    if (low < high)
    {        
        int mid = low+((high-low)/2);
 
        // Sort first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
 
        merge(arr, low, mid, high);
    }
}

// Divide and Conquer
int Utils::lowerIndex(const vector<int> & arr, int low, int high, int num, int size)
{
  if(high >= low)
  {
    int mid = low + ((high - low)/2);
    // If different number found or index 0
    if( ( mid == 0 || num > arr[mid-1]) && arr[mid] == num)
    {
      return mid;
    }
    // if num > arr[mid] search in upper half
    else if(num > arr[mid])
    {     
      return lowerIndex(arr, (mid + 1), high, num, size);
    }
    // if num < arr[mid] search in lower half
    else
    {
      return lowerIndex(arr, low, (mid -1), num, size);
    }
  }
  return -1;    // Not found code
}

// Divide and conquer
int Utils::upperIndex(const vector<int>& arr, int low, int high, int num, int size)
{

  if(high >= low)
  {
    int mid = low + ((high - low)/2);
    // If different number found or index is last
    if( ( mid == size-1 || num < arr[mid+1]) && arr[mid] == num )
    {
      return mid;
    }
    // If num < arr[mid] search lower half
    else if(num < arr[mid])
    {
      return upperIndex(arr, low, (mid -1), num, size);
    }
    // If num > arr[mid] search upper half
    else
    {
      return upperIndex(arr, (mid + 1), high, num, size);      
    }
  }
  return -1;    // Not found code
}