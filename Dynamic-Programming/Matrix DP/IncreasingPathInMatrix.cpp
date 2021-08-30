// Given an integer array A containing N integers.
// You need to divide the array A into two subsets S1 and S2 such that the absolute difference
//  between their sums is minimum.
// Find and return this minimum possible absolute difference.
// NOTE:
// Subsets can contain elements from A in any order (not necessary to be contiguous).
// Each element of A should belong to any one subset S1 or S2, not both.
// It may be possible that one subset remains empty.

// Problem Constraints
// 1 <= N <= 100
// 1 <= A[i] <= 100
// Input Format
// First and only argument is an integer array A.
// Output Format
// Return an integer denoting the minimum possible difference among the sums of two subsets.
// Example Input
// Input 1:
//  A = [1, 6, 11, 5]

// Example Output
// Output 1:
//  1
// Example Explanation
// Explanation 1:
//  Subset1 = {1, 5, 6}, sum of Subset1 = 12
//  Subset2 = {11}, sum of Subset2 = 11


vector<vector<int>> dp;

int helper(vector<vector<int>> &A, int i, int j, int n, int m){
    if(dp[i][j] != -1) return dp[i][j];
    int op1 = 0, op2 = 0;
    if(i+1 < n and A[i][j] < A[i+1][j])
        op1 = helper(A, i+1, j, n, m);
    if(j+1 < m and A[i][j] < A[i][j+1])
        op2 = helper(A, i, j+1, n, m);
    dp[i][j] = max(op1, op2) + 1;
    return dp[i][j];
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    dp.assign(n, vector<int>(m, -1));
    helper(A, 0, 0, n, m);
    return (dp[n-1][m-1] == -1) ? -1 : dp[0][0];
}