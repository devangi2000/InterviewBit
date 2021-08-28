// Given numRows, generate the first numRows of Pascal's triangle.
// Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1]
//  from previous row R - 1.
// Example:
// Given numRows = 5,
// Return  [ [1], [1,1], [1,2,1], [1,3,3,1], [1,4,6,4,1] ] 

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    for(int i = 0; i < A; i++){
        vector<int> temp;
        for(int j = 0; j <= i; j++){
            if(j == 0 or j == i)
                temp.push_back(1);
            else{
                int x = ans[i-1][j-1] + ans[i-1][j];
                temp.push_back(x);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}