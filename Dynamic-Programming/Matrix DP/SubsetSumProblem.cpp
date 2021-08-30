// Given an integer array A of size N.
// You are also given an integer B, you need to find whether their exist a subset
//  in A whose sum equal B.
// If there exist a subset then return 1 else return 0.
// Problem Constraints
// 1 <= N <= 100
// 1 <= A[i] <= 100
// 1 <= B <= 105
// Input Format
// First argument is an integer array A.
// Second argument is an integer B.
// Output Format
// Return 1 if there exist a subset with sum B else return 0.
// Example Input
// Input 1:
//  A = [3, 34, 4, 12, 5, 2]
//  B = 9
// Input 2:
//  A = [3, 34, 4, 12, 5, 2]
//  B = 30
// Example Output
// Output 1:
//  1
// Output 2:
//  0
// Example Explanation
// Explanation 1:
//  There is a subset (4, 5) with sum 9.
// Explanation 2:
//  There is no subset that add up to 30.


// THIS WORKS
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    if(B == 0) return 1;
    vector<vector<int>> dp(n+1, vector<int>(B+1, 0));
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= B; j++){
            if(A[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
        }
    }
    return dp[n][B];
}


// THIS IS SUPPOSED TO WORK BUT DOESN'T

vector<vector<int>> dp;

int knapsack(vector<int> &A, int n, int B){
    if(B == 0) return 1;
    if(n == 0) return 0;
    if(B < 0) return 0;
    if(dp[n][B] != -1) return dp[n][B];
    if(A[n] > B)
        return dp[n][B] = knapsack(A, n-1, B);
    return dp[n][B] = (knapsack(A, n-1, B) || knapsack(A, n-1, B-A[n]));
}

int Solution::solve(vector<int> &A, int B) {
    if(A.empty()) return 0;
    int n = A.size();
    dp.assign(n+1, vector<int>(B+1, -1));
    return knapsack(A, n, B);
}

