// Given an integer array A containing N integers.
// You need to divide the array A into two subsets S1 and S2 such that
//  the absolute difference between their sums is minimum.
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

int Solution::solve(vector<int> &A)
{
    int sum = 0, n = A.size(), ans = 0;
    for(auto a: A) sum += a;
    int summ = sum;
    sum/=2;
    vector<vector<int>> dp;
    dp.assign(n+1, vector<int>(sum + 1, 0));
    for(int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(A[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            if(dp[i][j] == 1)
                ans = j;
        }
    }
    return summ - 2*ans;
}