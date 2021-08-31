

vector<vector<int>> Solution::queenAttack(vector<string> &A) {
int r = A.size();
int c = A[0].size();
vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(8, 0)));
//top and bottom attack
for(int i=1; i<r; i++){
    for(int j=0; j<c; j++){
        if(A[i-1][j]=='1') dp[i][j][0] = 1;
        else dp[i][j][0] = dp[i-1][j][0];
        if(A[r-i][j]=='1') dp[r-i-1][j][4] = 1;
        else dp[r-i-1][j][4] = dp[r-i][j][4];
    }    
}
//left and right attack
for(int j=1; j<c; j++){
    for(int i=0; i<r; i++){
        if(A[i][j-1]=='1') dp[i][j][6] = 1;
        else dp[i][j][6] = dp[i][j-1][6];
        if(A[i][c-j]=='1') dp[i][c-j-1][2] = 1;
        else dp[i][c-j-1][2] = dp[i][c-j][2];
    }
}
//topLeft and bottomRight attack
for(int i=1; i<r; i++){
    for(int j=1; j<c; j++){
        if(A[i-1][j-1]=='1') dp[i][j][7] = 1;
        else dp[i][j][7] = dp[i-1][j-1][7];
        if(A[r-i][c-j]=='1') dp[r-i-1][c-j-1][3] = 1;
        else dp[r-i-1][c-j-1][3] = dp[r-i][c-j][3];
    }    
}
//topRight and bottomLeft
for(int i=1; i<r; i++){
    for(int j=c-2; j>=0; j--){
        if(A[i-1][j+1]=='1') dp[i][j][1] = 1;
        else dp[i][j][1] = dp[i-1][j+1][1];
        if(A[r-i][c-2-j]=='1') dp[r-i-1][c-1-j][5] = 1;
        else dp[r-i-1][c-1-j][5] = dp[r-i][c-j-2][5];
    }
}
vector<vector<int>> ans(r, vector<int>(c, 0));
for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
        for(int k=0; k<8; k++){
            ans[i][j] += dp[i][j][k];
        }
    }
}
return ans;
}