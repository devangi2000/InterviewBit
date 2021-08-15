// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell.
// The same letter cell may be used more than once.

// Example :

// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns 1,
// word = "SEE", -> returns 1,
// word = "ABCB", -> returns 1,
// word = "ABFSAB" -> returns 1
// word = "ABCD" -> returns 0
// Note that 1 corresponds to true, and 0 corresponds to false.


int solve(vector<string> &A, int i, int j, int k, string B){
    if(k >= B.size())
        return 1;
    
    if(i < 0 or j < 0 or i >= A.size() or j >= A[0].size() or A[i][j] != B[k])
        return 0;
        
    if(solve(A, i+1, j, k+1, B) or solve(A, i-1, j, k+1, B) or
        solve(A, i, j+1, k+1, B) or  solve(A, i, j-1, k+1, B)) 
        return 1;
    else 
        return 0;
}

int Solution::exist(vector<string> &A, string B) {
    int r = A.size(), n = B.size(), k=0;
    if(r == 0 or n == 0) return 0;
    
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < A[i].size(); ++j){
            if(B[0] == A[i][j])
                if(solve(A, i, j, k, B))
                    return 1;
        }
    }
    return 0;
}

