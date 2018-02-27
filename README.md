# NetVirta_Assessment
## Objectives ·         
1. To implement the search functions for sequence search, unordered search and closest match search. 
2. Speed up the search time and provide a solution to protect sensitive information of matrix data.
3. Write test cases to ensure the accuracy of search functions.

## Class Diagram
<div align="center">
	<img src="https://github.com/rahulnusiss/NetVirta_Assessment/blob/master/image/Search_Class.png?raw=true" width="480" height="640"/><br><br>
</div>

Assumption: Main is the entry point function not the class.
Description: 
1. This is the initial version of design diagram proposed for the solution.
2. The algorithm for search is distributed in 3 functions in Search class as shown in the diagram.
3. FileHandle class will take care of storing the matrix in file by encryting and loading the file by decrypting.
4. This is just proposed design diagram, some decision might lead to minor changes in the structure during implementation.

## Sequence Diagram
<div align="center">
	<img src="https://github.com/rahulnusiss/NetVirta_Assessment/blob/master/image/Search_Sequence.png?raw=true" width="480" heaight = "640"/><br><br>
</div>

Description:
1. The flow starts from main function which handles the objects of different class. 
2. TestSearch object will test the 3 search algorithms as per problem statement.
3. Some minor changes during implementation expected.