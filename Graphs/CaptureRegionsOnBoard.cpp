// Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.



// Problem Constraints
// 1 <= N, M <= 103



// Input Format
// First and only argument 2D character matrix A of size N X M.



// Output Format
// Make changes to the the input only as matrix is passed by reference.



// Example Input
// Input 1:

//  A = [  [X, X, X, X],
//         [X, O, O, X],
//         [X, X, O, X],
//         [X, O, X, X]
//      ]


// Example Output
// Output 1:

//  A = [  [X, X, X, X],
//         [X, X, X, X],
//         [X, X, X, X],
//         [X, O, X, X]
//      ]


// Example Explanation
// Explanation 1:

//  'O' in (4,2) is not surrounded by X from below.

void mark(vector<vector<char>> &board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = '1';
        mark(board, i+1, j);
        mark(board, i-1, j);
        mark(board, i, j-1);
        mark(board, i, j+1);
    }
 
void Solution::solve(vector<vector<char> > &board) {
    if(board.size() == 0) return;
        int r = board.size(), c = board[0].size();
        for(int i = 0; i < r; i++){
           mark(board, i, 0);
           mark(board, i, c-1);
        }
        for(int i = 0; i < c; i++){
           mark(board, 0, i);
           mark(board, r-1, i);
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
}