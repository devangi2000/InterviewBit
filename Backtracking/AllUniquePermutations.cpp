void solve(vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited, vector<int> &nums){
    if(temp.size() == nums.size()){
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(visited[i] || (i > 0 and nums[i] == nums[i-1] and !visited[i-1])) continue;
        visited[i] = true;
        temp.push_back(nums[i]);
        solve(ans, temp, visited, nums);
        visited[i] = false;
        temp.pop_back();
    }
}

vector<vector<int> > Solution::permute(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(nums.size(), false);
    sort(nums.begin(), nums.end());
    solve(ans, temp, visited, nums);
    return ans;
}
