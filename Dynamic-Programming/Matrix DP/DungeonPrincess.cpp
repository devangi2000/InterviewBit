// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
//  The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially
//  positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
// The knight has an initial health point represented by a positive integer. If at any point his health 
// point drops to 0 or below, he dies immediately.
// Some of the rooms are guarded by demons, so the knight loses health (negative integers)
//  upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that
//  increase the knight’s health (positive integers).
// In order to reach the princess as quickly as possible, the knight decides to move only 
// rightward or downward in each step.
// Write a function to determine the knight’s minimum initial health so that he is able to 
// rescue the princess.
// For example, given the dungeon below, the initial health of the knight must be at least 7 
// if he follows the optimal path
// RIGHT-> RIGHT -> DOWN -> DOWN.
// Dungeon Princess: Example 1
// Input arguments to function:
// Your function will get an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight’s minimum initial health required.

//  Note:
// The knight’s health has no upper bound.
// Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
// https://leetcode.com/problems/dungeon-game/discuss/698376/C%2B%2B-or-Beginner-friendly-dp-%2B-Explanation-and-idea
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9+5));
    dp[n][m-1] = 1;
    dp[n-1][m] = 1;
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            int need = min(dp[i+1][j], dp[i][j+1]) - A[i][j];
            dp[i][j] = max(1, need);
        }
    }
    return dp[0][0];
}

// Our dp looks like this:

// -2  -3   3  m      m -> denotes max 
// -5  10   1  m
// 10  30  -5  1   -> note: we have two value as 1 for the last element (I will explain this as we proceed)
//  m   m   1 m
 
//  suppose the dimensions of dungeon matirx was "r x c", for our dp will be " r+1 x c+1".
//  We will start our iteration 
//  from the value -5 that is the cell our princess is located.
//  We first have to see which value is minimum from that cell (the one on the right or bottom).
//  i.e. which cell requres less health to travel to
//  for this cell is (one which holds the princess):
//  val = min of dp[i+1][j] and dp[i][j+1] (min of bottom and right).
//  so val = min(1,1) = 1;
//  Also we have to reduce the health required to stay in the current cell.
//  val = val - dungeon[i][j] = 1 - (-5) = 6;
//  Now as i explained earlier:
//  dp[i][j] = max(1,val)   => if val is negetive that means we dont have to spend health on this cell so it should be kept minimum i.e. 1.
 
//  So we had to keep both values 1 as instead of max as for calculating the health for princess' cell we only need 1 health minimum. 
 
//  Now let's see for 2nd row 3rd column (one above the princess)
//  val = min(m,6) - 1;   (6 because the dp holds value 6 for princess' cell which was calculated earlier)
//  val = 5.
//  dp[1][2] = 5; So when we are at this cell we need health atleast 5. 
//  As we will gain 1 health and then move on to the princess's cell giving up  5  health and thus in this way we can calculate all the values.