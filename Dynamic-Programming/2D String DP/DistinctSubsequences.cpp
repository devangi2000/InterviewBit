// Given two sequences A, B, count number of unique ways in sequence A, to form a 
// subsequence that is identical to the sequence B.
// Subsequence : A subsequence of a string is a new string which is formed from the
//  original string by deleting some (can be none) of the characters without disturbing 
// the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE”
//  while “AEC” is not).

// Input Format:

// The first argument of input contains a string, A.
// The second argument of input contains a string, B.
// Output Format:

// Return an integer representing the answer as described in the problem statement.
// Constraints:
// 1 <= length(A), length(B) <= 700
// Example :
// Input 1:
//     A = "abc"
//     B = "abc"    
// Output 1:
//     1
// Explanation 1:
//     Both the strings are equal.
// Input 2:
//     A = "rabbbit" 
//     B = "rabbit"
// Output 2:
//     3
// Explanation 2:
//     These are the possible removals of characters:
//         => A = "ra_bbit" 
//         => A = "rab_bit" 
//         => A = "rabb_it"        
//     Note: "_" marks the removed character.

// https://leetcode.com/problems/distinct-subsequences/discuss/572192/Understand-DP-through-question-115-explanation-with-pictures

vector<vector<int>> dp;

int solve(string A, string B, int a, int b){
    if(dp[a][b] != -1)
        return dp[a][b];
    if(b <= 0)
        return dp[a][b] = 1;
    if(a <= 0)
        return dp[a][b] = 0;
    if(A[a-1] == B[b-1])
        return dp[a][b] = solve(A, B, a-1, b-1) + solve(A, B, a-1, b);
    return dp[a][b] = solve(A, B, a-1, b);
}

int Solution::numDistinct(string A, string B) {
    dp.clear();
    dp.resize(A.size() + 1, vector<int> (B.size() + 1, -1));
    return solve(A, B, A.size(), B.size());
}