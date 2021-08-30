// As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
// Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

// NOTE:

// Each dish is supposed to be eaten by only one person. Sharing is not allowed.
// Each friend can take any dish unlimited number of times.
// There always exists a dish with filling capacity 1 so that a solution always exists.
// Input Format

// Friends : List of integers denoting eating capacity of friends separated by space.
// Capacity: List of integers denoting filling capacity of each type of dish.
// Cost :    List of integers denoting cost of each type of dish.
// Constraints:
// 1 <= Capacity of friend <= 1000
// 1 <= No. of friends <= 1000
// 1 <= No. of dishes <= 1000

// Example:

// Input:
//     2 4 6
//     2 1 3
//     2 5 3

// Output:
//     14

// Explanation: 
//     First friend will take 1st and 2nd dish, second friend will take 2nd dish twice.  Thus, total cost = (5+3)+(3*2)= 14


int Solution::solve(const vector<int> &c, const vector<int> &wt, const vector<int> &val){
    int n = wt.size(); int T = c.size(), ans = 0, W = 0;
    
    for(int t=0; t < T; t++){
        W = max(W, c[t]);   
    }

    int dp[n+1][W+1];
    
    for(int i=0; i <= n; i++)
    for(int j=0; j <= W; j++){
        if(j == 0) dp[i][j] = 0;
        else if(i == 0) dp[i][j] = 1e9;
        else if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
        else dp[i][j] = min(dp[i-1][j], val[i-1] + dp[i][j-wt[i-1]]);
    }
    
    for(int t=0; t < T; t++) ans += dp[n][c[t]];
    return ans;
}


// OR

int Solution::solve(const vector<int> &c, const vector<int> &wt, const vector<int> &val){
    int n = *max_element(c.begin(), c.end());
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < wt.size(); j++){
            if(wt[j] <= i){
                dp[i] = min(dp[i], val[j] + dp[i - wt[j]]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < c.size(); i++){
        ans += dp[c[i]];
    }
    return ans;
}