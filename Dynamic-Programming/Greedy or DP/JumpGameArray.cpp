// Given an array of non-negative integers, A, you are initially positioned at the 0th index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.


// Input Format:

// The first and the only argument of input will be an integer array A.
// Output Format:

// Return an integer, representing the answer as described in the problem statement.
//     => 0 : If you cannot reach the last index.
//     => 1 : If you can reach the last index.
// Constraints:
// 1 <= len(A) <= 106

// 0 <= A[i] <= 30

// Examples:

// Input 1:
//     A = [2,3,1,1,4]

// Output 1:
//     1

// Explanation 1:
//     Index 0 -> Index 2 -> Index 3 -> Index 4

// Input 2:
//     A = [3,2,1,0,4]

// Output 2:
//     0

// Explanation 2:
//     There is no possible path to reach the last index.


int Solution::canJump(vector<int> &A) {
    int farthest = 0, n = A.size(), i;
    for(i = 0; i < n; i++){
        if(farthest < i) return 0;
        farthest = max(farthest, A[i]+i);
    }
    return 1;
}

// OR 


int Solution::canJump(vector<int> &A) {
    int farthest = 0, n = A.size(), i;
    for(i = 0; i < n and i <= farthest; i++){
        farthest = max(farthest, A[i]+i);
    }
    return i >= n;
}

