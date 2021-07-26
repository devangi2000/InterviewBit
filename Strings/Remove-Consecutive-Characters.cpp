// Problem Description

// Given a string A and integer B, remove all consecutive same characters that have length exactly B.

// Problem Constraints
// 1 <= |A| <= 100000

// 1 <= B <= |A|

// Input Format
// First Argument is string A.

// Second argument is integer B.
// Output Format
// Return a string after doing the removals.
// Example Input
// Input 1:

// A = "aabcd"
// B = 2
// Input 2:

// A = "aabbccd"
// B = 2
// Example Output
// Output 1:

//  "bcd"
// Output 2:

//  "d"

// Example Explanation
// Explanation 1:

//  "aa" had length 2.
// Explanation 2:

//  "aa", "bb" and "cc" had length of 2.


string Solution::solve(string A, int B) {
int n = A.size(), count = 0, i=0;
string ans = "";
while(i<n){
    count = 1;
    while(i<n-1 and A[i]==A[i+1]){
        count++;
        i++;
    }
    if(count!=B){
        while(count--) ans+=A[i];
    }
    i++;
}
return ans;
}
