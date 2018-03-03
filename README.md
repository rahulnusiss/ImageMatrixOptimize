# NetVirta_Assessment
## Objectives ·         
1. To implement the search functions for sequence search, unordered search and closest match search. 
2. Speed up the search time and provide a solution to protect sensitive information of matrix data.
3. Write test cases to ensure the accuracy of search functions.

## Class Diagram
<div align="center">
	<img src="https://github.com/rahulnusiss/NetVirta_Assessment/blob/master/image/Class_search_updated.png?raw=true" width="640" height="480"/><br><br>
</div>

Assumption: Main is the entry point function not the class.
Description: 
1. Class diagram after implementation.
2. The algorithm for search is distributed in 3 functions in Search class as shown in the diagram.
3. FileHandle class will take care of storing the matrix in file by encryting and loading the file by decrypting.

## Sequence Diagram
<div align="center">
	<img src="https://github.com/rahulnusiss/NetVirta_Assessment/blob/master/image/Sequence_search_updated.png?raw=true" width="480" heaight = "640"/><br><br>
</div>

Description:
1. The flow starts from main function which handles the objects of different class. 
2. TestSearch object will test the 3 search algorithms as per problem statement.

The detailed description of various method is provided in .h files in source.

### To run:
 Make source folder as pwd. Then: 
 `...../source$ sudo make`<br>
 ` ...../source$ ./output.out 'searchSequence 1 3 4 3 234 6 7'`<br>
  For unordered use 'searchUnordered' , for best match use 'searchBestMatch'.

## Other requirements
1. Matrix sensitive information: There is provision of encryption and decryption using encrypt and decrypt function in FileHandle Class. Encryption is done as follows:
	a. If ith + jth position of element in matrix is even then add +2 to the element, else add +3 to the element.
	b. to decrypt reverse the logic, subtract 2 if even else subtract 3.

2. Optimize the search function:
	Note: I have used map in which lookup run time is O(log n). It can be **replaced with exactly the same logic by unordered\_map whose lookup run time is O(1)**. I was in doubt that unordered map might throw error in other machines so **in order to avoid conflict with unordered_map, i have used map instead**.

	a. Sequence search: Overall complexity of sequence search is O(n^2). Although first we iterate through the number of appearence of seq[0], where seq[0] is the input sequence matrix. Let this no. of appearence of seq[0], first element in sequence matrix be X. So ideally complexity is O(X*n). Expected complexity should be very less than O(n^2). n is the number of columns in the input 2D matrix from file.

	b. Unordered search: For a single row there is only one iteration through sequence array. Let Y be the number of unique elements in sequence array. As we compare the counts from the map so optimized solution time complexity is O(Ylogn) by using map. By using unordered_map complexity is O(Y).

	c. Best Match search: Just like unordered case, we compare the counts from the map, but in this case instead of returning true or false we are calculating total match by adding values of matches from the count of 2 maps. Time complexity is O(Ylogn) by using map. By using unordered_map complexity is O(Y).

3. Design choices:
	a. Vector < Vector < int >> for dynamic array of input matrix file.
	b. map < int, int> to take counts of elements from sequence array as well as each row arrays from 2D matrix for faster processing.
	c. Design class and sequence diagram is shown. There is association between TestSearch and Search class as TestSearch class has to call the search algorithm for same matrix data file repeatedly.

4. To add more search functions, we can do it in Search class. This will give us the ability to run that search function on the same 2D matrix data.

5. Varying matrix dimension: As the dimension of matrix is handled dynamically, so changes in number of rows and columns is handled by nested vector.

6. Test case report is present in testcases folder.