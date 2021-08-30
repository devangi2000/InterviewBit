// Given a 2D integer array A of size M x N, you need to find a path from top left to bottom 
// right which minimizes the sum of all numbers along its path.
// NOTE: You can only move either down or right at any point in time.
//  Input Format
// First and only argument is an 2D integer array A of size M x N.

// Output Format
// Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

// Example Input
// Input 1:

//  A = [  [1, 3, 2]
//         [4, 3, 1]
//         [5, 6, 1]
//      ]

// Example Output
// Output 1:

//  9

// Example Explanation
// Explanation 1:

//  The path is 1 -> 3 -> 2 -> 1 -> 1
//  So ( 1 + 3 + 2 + 1 + 1) = 8

int Solution::minPathSum(vector<vector<int> > &A){
    int n = A.size(), m = A[0].size();
    if(n==0) return 0;
    if(n == 1 and m == 1) return A[0][0];
    
    for(int i=1;i<n;i++)
        A[i][0]=A[i-1][0]+A[i][0];

    for(int i=1;i<m;i++)
        A[0][i]=A[0][i-1]+A[0][i];
    
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            A[i][j] += min(A[i-1][j], A[i][j-1]);
            
    return A[n-1][m-1];
}


