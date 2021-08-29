// Given a N * 2 array A where (A[i][0], A[i][1]) represents the ith pair.
// In every pair, the first number is always smaller than the second number.
// A pair (c, d) can follow another pair (a, b) if b < c , similarly in this way a chain of pairs can be formed.
// Find the length of the longest chain subsequence which can be formed from a given set of pairs.
// Problem Constraints
// 1 <= N <= 103
// 1 <= A[i][0] < A[i][1] <= 104
// Input Format
// First and only argument is an 2D integer array A of size N * 2 representing the N pairs.
// Output Format
// Return a single integer denoting the length of longest chain subsequence of pairs possible under given constraint.
// Example Input
// Input 1:
//  A = [  [5, 24]
//         [39, 60]
//         [15, 28]
//         [27, 40]
//         [50, 90]
//      ]
// Input 2:
 
// A = [   [10, 20]
//         [1, 2]
//      ]

// Example Output
// Output 1:

//  3
// Output 2:

//  1

// Example Explanation
// Explanation 1:
//  Longest chain that can be formed is of length 3, and the chain is [ [5, 24], [27, 40], [50, 90] ]
// Explanation 2:
//  Longest chain that can be formed is of length 1, and the chain is [ [1, 2] ] or [ [10, 20] ]

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), maxend = A[0][1];
    vector<int> lis(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[j][1] < A[i][0]){
                lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}