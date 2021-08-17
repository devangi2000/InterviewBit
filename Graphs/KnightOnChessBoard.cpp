// Given any source point, (C, D) and destination point, (E, F) on a 
// chess board, we need to find whether Knight can move to the 
// destination or not.
// Knight's movements on a chess board
// The above figure details the movements for a knight ( 8 possibilities ).
// If yes, then what would be the minimum number of steps for the knight
//  to move to the said point.
// If knight can not move from the source point to the destination point,
//  then return -1.
// Note: A knight cannot go out of the board.

// Input Format:

// The first argument of input contains an integer A.
// The second argument of input contains an integer B.
//     => The chessboard is of size A x B.
// The third argument of input contains an integer C.
// The fourth argument of input contains an integer D.
//     => The Knight is initially at position (C, D).
// The fifth argument of input contains an integer E.
// The sixth argument of input contains an integer F.
//     => The Knight wants to reach position (E, F).
// Output Format:

// If it is possible to reach the destination point, return the minimum number of moves.
// Else return -1.
// Constraints:

// 1 <= A, B <= 500
// Example

// Input 1:
//     A = 8
//     B = 8
//     C = 1
//     D = 1
//     E = 8
//     F = 8
    
// Output 1:
//     6

// Explanation 1:
//     The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
//     The minimum number of moves required for this is 6.


int Solution::knight(int A, int B, int C, int D, int E, int F) {
     vector<int> X = {1, 1, -1, -1,2, 2, -2, -2};
     vector<int> Y = {2, -2, 2, -2, 1, -1, 1, -1};
     vector<vector<int>> visited(A+2, vector<int>(B+2, 0));
     queue<pair<int, pair<int, int>>> q;
     q.push({0,{C, D}});
     visited[C][D] = 1;
     while(!q.empty()){
         auto curr = q.front();
         int moves = curr.first;
         int dx = curr.second.first;
         int dy = curr.second.second;
         q.pop();
         
         if(dx == E and dy == F)
            return moves;
         for(int i = 0; i < 8; i++){
             int x = dx + X[i];
             int y = dy + Y[i];
             if(x >= 1 and y >= 1 and x <= A and y <= B and !visited[x][y]){
                 visited[x][y] = 1;
                 q.push({moves+1, {x, y}});
             }
         }   
        
     }
     return -1;
}

