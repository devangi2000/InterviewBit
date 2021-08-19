// Given a sorted array of integers A(0 based index) of size N, find the 
// starting and ending position of a given integar B in array A.
// Your algorithm’s runtime complexity must be in the order of O(log n).
// Return an array of size 2, such that first element = starting position of 
// B in A and second element = ending position of B in A, if B is not found 
// in A return [-1, -1].

// Input Format

// The first argument given is the integer array A.
// The second argument given is the integer B.
// Output Format

//  Return an array of size 2, such that first element = starting position
//  of B in A and second element = ending position of B in A, if B is not 
// found in A return [-1, -1].
// Constraints

// 1 <= N <= 10^6
// 1 <= A[i], B <= 10^9
// For Example

// Input 1:
//     A = [5, 7, 7, 8, 8, 10]
//     B = 8
// Output 1:
//     [3, 4]
// Explanation 1:
//     First occurence of 8 in A is at index 3
//     Second occurence of 8 in A is at index 4
//     ans = [3, 4]

// Input 2:
//     A = [5, 17, 100, 111]
//     B = 3
// Output 2:
//     [-1, -1]

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int start = 0, mid = 0, end = A.size() - 1, first = -1, last = -1;
    while(start <= end){
        int mid = (start + end) >> 1;
        if(B == A[mid]){
            first = mid;
            end = mid - 1;
        }
        else if(B < A[mid]){
            end = mid - 1;
        }
        else if(B > A[mid]){
            start = mid + 1;
        }
    }
    start = 0, mid = 0, end = A.size() - 1;
    while(start <= end){
        int mid = (start + end) >> 1;
        if(B == A[mid]){
            last = mid;
            start = mid + 1;
        }
        else if(B < A[mid]){
            end = mid - 1;
        }
        else if(B > A[mid]){
            start = mid + 1;
        }
    }
    return {first, last};
}