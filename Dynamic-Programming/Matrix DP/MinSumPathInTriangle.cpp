// Given a triangle, find the minimum path sum from top to bottom. 
// Each step you may move to adjacent numbers on the row below.
// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//  Note:
// Bonus point if you are able to do this using only O(n) extra space, where n
//  is the total number of rows in the triangle. 

int Solution::minimumTotal(vector<vector<int> > &A){
    int n = A.size();
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < A[i].size(); j++){
            A[i][j] += min(A[i+1][j], A[i+1][j+1]);
        }
    }
    return A[0][0];
}

// OR

int Solution::minimumTotal(vector<vector<int> > &A){
    int n = A.size(), m = A[n-2].size();
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < m; j++){
            A[i][j] += min(A[i+1][j], A[i+1][j+1]);
        }
        m--;
    }
    return A[0][0];
}