// Given an array A of size N. You need to find the sum of Maximum and
//  Minimum element in the given array.
// NOTE: You should make minimum number of comparisons.
// Problem Constraints
// 1 <= N <= 105
// -109 <= A[i] <= 109
// Input Format
// First and only argument is an integer array A of size N.
// Output Format
// Return an integer denoting the sum Maximum and Minimum element in the given array.
// Example Input
// Input 1:
//  A = [-2, 1, -4, 5, 3]
// Input 2:
//  A = [1, 3, 4, 1]
// Example Output
// Output 1:
//  1
// Output 2:
//  5
// Example Explanation
// Explanation 1:
//  Maximum Element is 5 and Minimum element is -4. (5 + (-4)) = 1. 
// Explanation 2:
//  Maximum Element is 4 and Minimum element is 1. (4 + 1) = 5.

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int mini = INT_MAX, maxi = INT_MIN;
    if(n == 0) return 0;
    for(int i = 0; i < n; i++){
        mini = min(mini, A[i]);
        maxi = max(maxi, A[i]);
    }
    return mini+maxi;
}

// OR

int Solution::solve(vector<int> &A) {
    return (*max_element(A.begin(),A.end()))+(*min_element(A.begin(),A.end()));
}