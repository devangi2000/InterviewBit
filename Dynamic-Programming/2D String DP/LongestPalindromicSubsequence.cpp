// Given a string A, find the common palindromic sequence
//  ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

// You need to return the length of longest palindromic subsequence in A.
// NOTE:
// Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.
// Problem Constraints
// 1 <= |A| <= 1005
// Input Format
// First and only argument is an string A.
// Output Format
// Return a integer denoting the length of longest palindromic subsequence in A.
// Example Input
// Input 1:
//  A = "bebeeed"
// Example Output
// Output 1:
//  4
// Example Explanation
// Explanation 1:
//  The longest common pallindromic subsequence is "eeee", which has a length of 4


int Solution::solve(string A) {
    string B = A;
    reverse(A.begin(), A.end());
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
