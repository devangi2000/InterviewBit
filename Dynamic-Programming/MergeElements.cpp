// Given an integer array A of size N. You have to merge all the elements of the array
// into one with the minimum possible cost.
// The rule for merging is as follows:
// Choose any two adjacent elements of the array with values say X and Y and merge them
// into a single element with value (X + Y) paying a total cost of (X + Y).
// Return the minimum possible cost of merging all elements.

// Problem Constraints
// 1 <= N <= 200
// 1 <= A[i] <= 103

// Input Format
// First and only argument is an integer array A of size N.

// Output Format
// Return an integer denoting the minimum cost of merging all elements.

// Example Input
// Input 1:

//  A = [1, 3, 7]
// Input 2:

//  A = [1, 2, 3, 4]

// Example Output
// Output 1:

//  15
// Output 2:

//  19
// Example Explanation
// Explanation 1:

//  All possible ways of merging:
//  a) {1, 3, 7} (cost = 0) -> {4, 7} (cost = 4) -> {11} (cost = 4+11 = 15)
//  b) {1, 3, 7} (cost = 0) -> {1, 10} (cost = 10) -> {11} (cost = 10+11 = 21)
//  Thus, ans = 15


int solve(int i, int j, vector<vector<int>> &dp, vector<int> &A){
    if(i >= j)
        return dp[i][j] = 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    int sum = 0;
    for(int x = i; x <= j; x++)
        sum += A[x];
        
    for(int k = i; k < j; k++){
        int a = solve(i, k, dp, A);
        int b = solve(k+1, j, dp, A);
        int temp = sum + a + b;
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
    
}
