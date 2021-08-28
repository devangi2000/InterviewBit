// Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.
// Input Format:
// The first and the only argument contains an integer, A.
// Output Format:
// Return a 2-d matrix of size A x A satisfying the spiral order.
// Constraints:
// 1 <= A <= 1000
// Examples:
// Input 1:
//     A = 3
// Output 1:
//     [   [ 1, 2, 3 ],
//         [ 8, 9, 4 ],
//         [ 7, 6, 5 ]   ]
// Input 2:
//     4
// Output 2:
//     [   [1, 2, 3, 4],
//         [12, 13, 14, 5],
//         [11, 16, 15, 6],
//         [10, 9, 8, 7]   ]


vector<vector<int> > Solution::generateMatrix(int A) {
    int dir = 0, top = 0, down = A-1, left = 0, right = A-1, n = A*A, i = 1;
    vector<vector<int>> ans(A, vector<int> (A));
    while(top <= down and left <= right){
        for(int j = left; j <= right; j++){
            ans[top][j] = i++;
        }
        top++;
        for(int j = top; j <= down; j++){
            ans[j][right] = i++;
        }
        right--;
        for(int j = right; j >= left; j--){
            ans[down][j] = i++;
        }
        down--;
        for(int j = down; j >= top; j--){
            ans[j][left] = i++;
        }
        left++;
    }
    return ans;
}