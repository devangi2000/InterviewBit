// Given N x M character matrix A of O's and X's, where O = white, X = black.

// Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



// Input Format:

//     The First and only argument is a N x M character matrix.
// Output Format:

//     Return a single integer denoting number of black shapes.
// Constraints:

//     1 <= N,M <= 1000
//     A[i][j] = 'X' or 'O'
// Example:

// Input 1:
//     A = [ OOOXOOO
//           OOXXOXO
//           OXOOOXO  ]
// Output 1:
//     3
// Explanation:
//     3 shapes are  :
//     (i)    X
//          X X
//     (ii)
//           X
//     (iii)
//           X
//           X
// Note: we are looking for connected shapes here.

// XXX
// XXX
// XXX
// is just one single connected black shape.

void dfs(vector<string> &A, int i, int j, int r, int c){
    if(i < 0 or i >= r or j < 0 or j >= c or A[i][j] == 'O')
        return;
    A[i][j] = 'O';
    dfs(A, i+1, j, r , c);
    dfs(A, i-1, j, r, c);
    dfs(A, i, j+1, r, c);
    dfs(A, i, j-1, r, c);
}

int Solution::black(vector<string> &A) {
    int r = A.size(), c = A[0].size(), ans = 0;;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(A[i][j] == 'X'){
                dfs(A, i, j, r, c);
                ans++;
            }
        }
    }
    return ans;
}

