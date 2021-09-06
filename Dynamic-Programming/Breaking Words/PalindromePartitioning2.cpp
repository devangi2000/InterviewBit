// Given a string A, partition A such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of A.

// Input Format:
// The first and the only argument contains the string A.
// Output Format:
// Return an integer, representing the answer as described in the problem statement.
// Constraints:
// 1 <= length(A) <= 501
// Examples:
// Input 1:
//     A = "aba"
// Output 1:
//     0
// Explanation 1:
//     "aba" is already a palindrome, so no cuts are needed.
// Input 2:
//     A = "aab"    
// Output 2:
//     1
// Explanation 2:
//     Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


vector<vector<int>> dp;
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    int solve(string &s, int start, int end){
        if(start>=end or isPalindrome(s, start, end)) return dp[start][end]=0;
        if(dp[start][end] != -1) return dp[start][end];
        int mn = INT_MAX;
        for(int i = start; i < end; i++){
            if(isPalindrome(s, start, i))
                mn = min(mn, 1 + solve(s, i+1, end));
        }
        return dp[start][end] = mn;
    }

int Solution::minCut(string s){
    dp.clear();
    int n = s.size();
    dp.resize(n, vector<int> (n, -1));
    return solve(s, 0, s.size()-1); 
}
