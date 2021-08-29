// Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.

// Return both parts (If exist). If there is no solution. return an empty list.

// NOTE:

// If a solution exists, you should return a list of exactly 2 lists of integers A and B which follow the following condition :
// numElements in A <= numElements in B
// If numElements in A = numElements in B, then A is lexicographically smaller than B ( https://en.wikipedia.org/wiki/Lexicographical_order )
// If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.

// Array will contain only non negative numbers.



// **Input Format**
// First andonly argument is an integer array A.



// **Output Format**
// Return 2D array consisting of two rows where each row denoted a partition.



// **Example Input**
// Input 1:

//  A = [1 7 15 29 11 9]


// Example Output
// Output 1:

//  [9 15] [1 7 11 29]


// Example Explanation
// Explanation 1:

//  The average of part is (15+9)/2 = 12, average of second part elements is (1 + 7 + 11 + 29) /

