Note: The input argument array is considered as sequence array.

Brute Force:   

    1. Sequence: 
        a. 2D array as vector of vector.
        b. For each row from 2D array, take first element of argument(sequence) array and check the index of same number in the row.
        c. Store the index in a vector. Lets call this vector as index_vec.
        d. Iterate over each index of the index_vec.
        e. We check the sequence in row from the index value which gives us the first element to look for sequence in row.
        e. If the sequence in row matches the sequence array from input args, return true.
        f. Complexity to check per row is O(n^2).

    2. Unordered:
        a. 2D array as vector of vector.
        b. We check the unordered match from 2D matrix by taking each row one by one like Sequence search.
        c. Take a map with elements inside sequence array as key, and their count in sequence array as value.
        d. Take the unique numbers which are stored as key in map. Check their count should not exceed their count in row.
        e. If the sequence array number count exceeds, that means all the required numbers of input array is not present in the row.
        f. If all the counts in map are less than or equal to counts in the row, return true.
        g. Complexity to check if all required numbers present per row is O(n^2).

    3. Best match:
        a. Just like case 2(unordered) store the count of each unique element from sequence(input args) array in a map.
        b. Now instead of returning true or false we take total number of matches.
        c. Take each number from the map key and check its count in both the arrays.
        d. Take the value of count whichever is less and add it to the total match.
        e. Return the value of total match and keep it as best match if it is the highest match value.
        f. Print the highest matching row.
        g. Time complexity for this would be O(n^2).

    Optimized:

        1. Sequence:
            a. Same. Complexity is O(X * n ). n = number of columns in 2D matrix, X = no. of seq[0](first element of sequence array) in row array of 2D matrix.

        2. Unordered:
            a. Take the counts of each unique number from both the arrays in separate maps.
            b. Compare counts from both the maps. If all counts in map_sequence is less than the counts in map_matrix_row, then return true.
            c. The complexity in this case would be O(3*n) ~ O(n) for unordered_map. For map its O(nlogn).

        3. Best match.
            a. Like unordered case take counts in two maps.
            b. Calculate total matches by adding the common counts value.
            c. The common counts value would be the count whose value is less.
            d. The complexity would be O(3*n) ~ O(n) for unordered_map. For map its O(nlogn).