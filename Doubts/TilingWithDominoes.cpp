// Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.

// Return the answer modulo 109 + 7 .

// NOTE:

// See the sample explanation for better understanding.


// Problem Constraints
// 1 <= A <= 105



// Input Format
// First and only argument is an integer A.



// Output Format
// Return an integer denoting the number of ways to fill a 3 x A board with 2 x 1 dominoes with modulo 109 + 7.



// Example Input
// Input 1:

//  2
// Input 2:

//  1


// Example Output
// Output 1:

//  3
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  Following are all the 3 possible ways to fill up a 3 x 2 board.
 
// Explanation 2:

//  Not a even a single way exists to completely fill the grid of size 3 x 1.

int Solution::solve(int A)
{
    long long int dp[A+1];
    dp[0]=1;
    dp[1]=0;
    dp[2]=3;
    for(int i=3;i<=A;i++)
    {
        if(i%2==1)
        dp[i]=0;
        else
        dp[i]=((dp[i-2]*4)%1000000007-dp[i-4]%1000000007+1000000007)%1000000007;
    }
    return dp[A];
}