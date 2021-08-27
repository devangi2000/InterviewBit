// Given a sorted array A containing N integers both positive and negative.
// You need to create another array containing the squares of all the elements
//  in A and return it in non-decreasing order.
// Try to this in O(N) time.

// Problem Constraints
// 1 <= N <= 105.
// -103 <= A[i] <= 103

// Input Format
// First and only argument is an integer array A.

// Output Format
// Return a integer array as described in the problem above.

// Example Input
// Input 1:

//  A = [-6, -3, -1, 2, 4, 5]
// Input 2:

//  A = [-5, -4, -2, 0, 1]

// Example Output
// Output 1:

//  [1, 4, 9, 16, 25, 36]
// Output 2:

//  [0, 1, 4, 16, 25]

vector<int> Solution::solve(vector<int> &A) {
    int n = A.size(), start = 0, end = n-1, k = n-1;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(abs(A[start]) >= abs(A[end])){
            ans[k--] = A[start] * A[start];
            start++;
        }
        else{
            ans[k--] = A[end] * A[end];
            end--;
        }
    }
    return ans;
}
