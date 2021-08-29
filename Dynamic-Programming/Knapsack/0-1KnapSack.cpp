// Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

// Also given an integer C which represents knapsack capacity.

// Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

// NOTE:

// You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).


// Problem Constraints
// 1 <= N <= 103

// 1 <= C <= 103

// 1 <= A[i], B[i] <= 103



// Input Format
// First argument is an integer array A of size N denoting the values on N items.

// Second argument is an integer array B of size N denoting the weights on N items.

// Third argument is an integer C denoting the knapsack capacity.



// Output Format
// Return a single integer denoting the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.



// Example Input
// Input 1:

//  A = [60, 100, 120]
//  B = [10, 20, 30]
//  C = 50
// Input 2:

//  A = [10, 20, 30, 40]
//  B = [12, 13, 15, 19]
//  C = 10


// Example Output
// Output 1:

//  220
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  Taking items with weight 20 and 30 will give us the maximum value i.e 100 + 120 = 220
// Explanation 2:

//  Knapsack capacity is 10 but each item has weight greater than 10 so no items can be considered in the knapsack therefore answer is 0.


// MEMOIZATION

vector<vector<int>> dp;

int knapsack(vector<int> &values, vector<int> &weights, int capacity, int n){
    if(capacity == 0 || n == 0) return 0;
    if(dp[n][capacity] != -1) return dp[n][capacity];
    if(weights[n-1] > capacity)
        return dp[n][capacity] = knapsack(values, weights, capacity, n-1);
    return dp[n][capacity] = max(knapsack(values, weights, capacity, n-1), 
                            values[n-1] + knapsack(values, weights, capacity - weights[n-1], n-1));
}


int Solution::solve(vector<int> &values, vector<int> &weights, int capacity){
    int n = values.size();
    dp.assign(n+1, vector<int>(capacity+1, -1));
    return knapsack(values, weights, capacity, n);
}

// TABULAR DP

int Solution::solve(vector<int> &values, vector<int> &weights, int capacity){
    int n = values.size();
    vector<vector<int>> dp;
    dp.assign(n+1, vector<int>(capacity+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if(weights[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
        }
    }
    return dp[n][capacity];
}
