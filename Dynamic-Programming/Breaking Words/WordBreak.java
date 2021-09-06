// Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated 
// sequence of one or more dictionary words.
// Input Format:
// The first argument is a string, A.
// The second argument is an array of strings, B.
// Output Format:
// Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
// Constraints:
// 1 <= len(A) <= 6500
// 1 <= len(B) <= 10000
// 1 <= len(B[i]) <= 20
// Examples:
// Input 1:
//     A = "myinterviewtrainer",
//     B = ["trainer", "my", "interview"]
// Output 1:
//     1
// Explanation 1:
//     Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
    // Input 2:
//     A = "a"
//     B = ["aaa"]
// Output 2:
//     0
// Explanation 2:
//     Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".
public class Solution {
    public int wordBreak(String s, String[] wordDict) {
        if(s.length() == 0) return 0;
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        Set<String> words = new HashSet<String>();
        for(String word : wordDict)
            words.add(word);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                dp[i] = dp[j] && words.contains(s.substring(j, i));
                if(dp[i]) break;
            }
        }
        return dp[n] ? 1 : 0;
    }
}
