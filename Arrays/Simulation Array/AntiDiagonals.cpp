// Give a N*N square matrix, return an array of its anti-diagonals. 
// Look at the example for more details.
// Example:
// Input:
// 1 2 3
// 4 5 6
// 7 8 9
// Return the following:
// [ 
//   [1],
//   [2, 4],
//   [3, 5, 7],
//   [6, 8],
//   [9]
// ]
// Input: 
// 1 2
// 3 4
// Return the following: 
// [
//   [1],
//   [2, 3],
//   [4]
// ]

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), t = (2*n) - 1;
    vector<vector<int>> ans(t);
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            ans[i+j].push_back(A[i][j]);
        }
    }
    return ans;
}