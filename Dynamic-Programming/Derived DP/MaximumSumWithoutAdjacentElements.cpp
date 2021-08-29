// Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
// is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally,
//  and return it.
// Note: You can choose more than 2 numbers.
// Input Format:
// The first and the only argument of input contains a 2d matrix, A.
// Output Format:
// Return an integer, representing the maximum possible sum.
// Constraints:
// 1 <= N <= 20000
// 1 <= A[i] <= 2000
// Example:

// Input 1:
//     A = [   [1]
//             [2]    ]

// Output 1:
//     2

// Explanation 1:
//     We will choose 2.

// Input 2:
//     A = [   [1, 2, 3, 4]
//             [2, 3, 4, 5]    ]
    
// Output 2:
//     We will choose 3 and 5.



int Solution::adjacent(vector<vector<int> > &A){
    int n = A[0].size();
    for(int i = 0; i < n; ++i)
        A[0][i] = max(A[0][i], A[1][i]);
    
    A[0][1] = max(A[0][0], A[0][1]);
    
    for(int i = 2; i < n; ++i)
        A[0][i]= max(A[0][i-1], A[0][i-2] + A[0][i]);
        
    return max(A[0][n-1], A[0][n-2]);
    
}

// OR just take another dp array for better understanding

int Solution::adjacent(vector<vector<int> > &A){
    int n = A[0].size();
    vector<int> dp(n+1);
    for(int i = 0; i < n; ++i)
        dp[i] = max(A[0][i], A[1][i]);
    dp[1] = max(dp[1], dp[0]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i] + dp[i-2]);
    }
    return max(dp[n-1], dp[n-2]);
}