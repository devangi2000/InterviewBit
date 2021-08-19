// You are given an array A having N integers.

// You have to perform the following steps in a given order.

// 1) generate all subarrays of A.

// 2) take the maximum element from each subarray of A and insert it into a new array G.

// 3) replace every element of G with the product of their divisors mod 1e9 + 7.

// 4) sort G in descending order

// You now need to perform Q queries

// In each query, you are given an integer K, where you have to find the Kth element in G.

// NOTE : Your solution will run on multiple test cases so do clear global variables after using them.



// Problem Constraints
// 1 <= N <= 1e5

// 1 <= A[i] <= 1e5

// 1 <= Q <= 1e5

// 1 <= k <= (N * (N + 1))/2



// Input Format
// The first argument given is an Array A, having N integers.

// The second argument given is an Array B, where B[i] is the ith query.



// Output Format
// Return an Array X, where X[i] will have the answer for the ith query.



// Example Input
// Input 1:

//  A = [1, 2, 4]
// B = [1, 2, 3, 4, 5, 6]
// Input 2:

//  A = [1, 3]
// B = [1]


// Example Output
// Output 1:

//  [8, 8, 8, 2, 2, 1]
// Output 2:

//  [3]