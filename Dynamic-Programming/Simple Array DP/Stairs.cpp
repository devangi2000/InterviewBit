// You are climbing a stair case and it takes A steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Input Format:
// The first and the only argument contains an integer A, the number of steps.
// Output Format:
// Return an integer, representing the number of ways to reach the top.
// Constrains:
// 1 <= A <= 36
// Example :
// Input 1:
// A = 2 Output 1:
// 2 Explanation 1:
// [1, 1], [2] Input 2:
// A = 3 Output 2:
// 3 Explanation 2: 
// [1 1 1], [1 2], [2 1]

int Solution::climbStairs(int A) {
    vector<int> dp(A+1);
    if(A <= 1) return 1;
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= A; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[A];
}
