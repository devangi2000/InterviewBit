// Given A, B, C, find whether C is formed by the interleaving of A and B.

// Input Format:*

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// The third argument of input contains a string, C.
// Output Format:

// Return an integer, 0 or 1:
//     => 0 : False
//     => 1 : True
// Constraints:

// 1 <= length(A), length(B), length(C) <= 150
// Examples:

// Input 1:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbcbcac"

// Output 1:
//     1
    
// Explanation 1:
//     "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

// Input 2:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbbaccc"

// Output 2:
//     0

// Explanation 2:
//     It is not possible to get C by interleaving A and B.

int Solution::isInterleave(string A, string B, string C) {
    int n = A.size(), m = B.size(), s = C.size();
    if(n + m != s) return 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <=n; i++){
        if(A[i-1] == C[i-1])
            dp[i][0] = 1;
        else break;
    }
    for(int j = 1; j <= m; j++){
        if(B[j-1] == C[j-1])
            dp[0][j] = 1;
        else break;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i-1] == C[i+j-1] || B[j-1] == C[i+j-1])
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][m];
}


// OR

int Solution::isInterleave(string A, string B, string C) {
    int n = A.size(), m = B.size(), s = C.size();
    if(n + m != s) return 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 and j == 0) dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = dp[i][j-1] and (B[j-1] == C[j-1]);
            else if(j == 0)
                dp[i][j] = dp[i-1][j] and (A[i-1] == C[i-1]);
            else if(A[i-1] == C[i+j-1] || B[j-1] == C[i+j-1])
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][m];
}


// OR
vector<vector<int>> dp;
int solve(string A, string B, string C, int n, int m, int s){
    if(s == 0)
        return dp[n][m] = 1;
    if(dp[n][m] != -1)
        return dp[n][m];
    int a = 0, b = 0;
    if(n > 0 and A[n-1] == C[s-1])
        a = solve(A, B, C, n-1, m, s-1);
    if(m > 0 and B[m-1] == C[s-1])
        b = solve(A, B, C, n, m-1, s-1);
    return dp[n][m] = a or b;
}

int Solution::isInterleave(string A, string B, string C) {
    int n = A.size(), m = B.size(), s = C.size();
    dp.assign(n+1, vector<int>(m+1, -1));
    return (n + m == s) and solve(A, B, C, n, m, s);
}
