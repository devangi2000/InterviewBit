// Problem Description
// Given an integer A.
// Compute and return the square root of A.
// If A is not a perfect square, return floor(sqrt(A)).
// DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.
// NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.

// Input Format
// The first and only argument given is the integer A.

// Output Format
// Return floor(sqrt(A))

// Example Input
// Input 1:
//  11
// Input 2:
//  9

// Example Output
// Output 1:

//  3
// Output 2:
//  3

// Example Explanation
// Explanation:

//  When A = 11 , square root of A = 3.316. It is not a perfect square so we return
//  the floor which is 3.
//  When A = 9 which is a perfect square of 3, so we return 3.

int Solution::sqrt(int A) 
{
    if(A == 0) return 0;
    int start = 1, end = A, ans = 1;
    while(start <= end){
        int mid = (start + end) >> 1;
        if(mid <= (A/mid)){ //  mid * mid <= A (here mid * mid could potentially give an overflow so divide it)
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}
