# NetVirta_Assessment
## Objectives ·         
1. To implement the search functions for sequence search, unordered search and closest match search. 
2. Speed up the search time and provide a solution to protect sensitive information of matrix data.
3. Write test cases to ensure the accuracy of search functions.

## Class Diagram
<div align="center">
	<img src="https://github.com/rahulnusiss/NetVirta_Assessment/blob/master/image/Restructured_design_class_diagram.png?raw=true" width="1000" height="800"/><br><br>
</div>

Assumption: Main is the entry point function not the class.
Description: 
1. Class diagram after implementation.
2. The algorithm for search is distributed in 3 functions in three different class implementing the same search interface as shown in the diagram.
3. Util class will take care of sorting the matrix and all other divide and conquer algorithm. ALso has some utility function like display.
4. lowerIndex and upperIndex functions finds the number's lowest index and highest index in logn time.
5. For unordered and best match search we sort each row of nput 2D matrix.

## Sequence Diagram
<div align="center">
	<img src="https://github.com/rahulnusiss/NetVirta_Assessment/blob/master/image/Restructured_design_sequence.png?raw=true" width="800" heaight = "1000"/><br><br>
</div>

Description:
1. The flow starts from main function which calls TestSearch class to call search function.
2. The search is mapped in TestSearch class constructor with search type having its object as key and value pair.
3. The testSearch function simply calls the search specified in input argument while benchMark function gives the time in 10^-6 seconds while running over 1000 iterations on different matrices with randomn numbers. The call to search is generic.

The detailed description of various method is provided in .h files in source.

### To run:
 Make source folder as pwd. Then: 

 `...../source$ sudo make`<br>
 ` ...../source$ ./output.out 'searchSequence 1 3 4 3 234 6 7'`<br>

  For unordered use 'searchUnordered' , for best match use 'searchBestMatch'.

## Other requirements
1. **Matrix sensitive information**: There is provision of encryption and decryption using encrypt and decrypt function in FileHandle Class. Encryption is done as follows:

	a. If ith + jth position of element in matrix is even then add +2 to the element, else add +3 to the element.

	b. to decrypt reverse the logic, subtract 2 if even else subtract 3.

2. **Optimize the search function**:

	a. ***Sequence search***: 
	Overall complexity of sequence search is O(n). Although first we iterate through the number of appearence of seq[0], where seq is the input sequence matrix. Let this no. of appearence of seq[0] ( first element in sequence matrix ) in row array, be X. So ideally complexity is O(X*n). n is the number of columns in the input 2D matrix from file.

	b. ***Unordered search***: 
	Before performing unordered search we sort the rows so that we could apply divide and conquer. For a single row there is only one iteration through sequence array. As we calculate the counts from the divide and conquer technique so optimized solution time complexity is O(logn).O(logn) by finding lowest index and highest index through divide and conquer and then calculate count using highestindex - lowestindex for each element of sequence array.

	c. ***Best Match search***: 
	Sort the row of 2d matrix to apply divide and conquer. Just like unordered case, we compare the counts from the map, but in this case instead of returning true or false we are calculating total match by adding values of matches from the two counts. Complexity is O(logn) by finding lowest index and highest index through divide and conquer and then calculate count using highestindex - lowestindex for each element of sequence array.

3. **Design choices**:

	a. Vector < Vector < int >> for dynamic array of input matrix file.

	b. map < int, int> to take counts of elements from sequence array as well as each row arrays from 2D matrix for faster processing. Map also for registering search object to search type.

	c. Design class and sequence diagram is shown. There is association between TestSearch and Search class as TestSearch class has to call the search algorithm for same matrix data file repeatedly.

	d. Sorted arrays for unordered and best match search to apply divide and conquer. Utils class has implementation of lowestIndex and upperIndex functions implementing O(logn )solution.

4. **To add more search functions**, we can do it by adding new search class. Map this search class in constructor of TestSearch.

5. **Varying matrix dimension**: As the dimension of matrix is handled dynamically, so changes in number of rows and columns is handled by nested vector.

6. Test case report is present in testcases folder.