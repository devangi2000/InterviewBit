// Given an integer array A of size N.
// You need to check that whether there exist a element which is strictly greater 
// than all the elements on left of it and strictly smaller than all the elements
// on right of it.
// If it exists return 1 else return 0.
// NOTE:
// Do not consider the corner elements i.e A[0] and A[N-1] as the answer.
// Problem Constraints
// 3 <= N <= 105
// 1 <= A[i] <= 109
// Input Format
// First and only argument is an integer array A containing N integers.
// Output Format
// Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it else return 0.
// Example Input
// Input 1:
//  A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
// Input 2:
//  A = [5, 1, 4, 4]
// Example Output
// Output 1:
//  1
// Output 2:
//  0
// Example Explanation
// Explanation 1:
//  A[4] = 6 is the element we are looking for.
//  All elements on left of A[4] are smaller than it and all elements on right are greater.
// Explanation 2:

//  No such element exists.

int Solution::perfectPeak(vector<int> &v) {
    int n = v.size(), i;
    int pos_ind = -1; // the index where the given conditions are satisfied
    int max_left = v.front();
    
    for(int i = 1; i < n; i++){
        if(pos_ind != -1){
            if(v[i] <= v[pos_ind])
                pos_ind = -1;
        }
        else{
            if(v[i] > max_left){
                pos_ind = i;
            }
        }
        max_left = max(max_left, v[i]);
    }
    return pos_ind != -1 && pos_ind != n - 1;
}