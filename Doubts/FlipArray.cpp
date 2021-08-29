// Given an array of positive elements, you have to flip the sign of some of its elements 
// such that the resultant sum of the elements of array should be minimum non-negative(as
//  close to zero as possible). Return the minimum no. of elements whose sign needs to be 
// flipped such that the resultant sum is minimum non-negative.
// Constraints:
//  1 <= n <= 100
// Sum of all the elements will not exceed 10,000.
// Example:
// A = [15, 10, 6]
// ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )
// A = [14, 10, 4]
// ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)
//  Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum 

int Solution::solve(const vector<int> &nums) {
    int n = nums.size();
    int sum=0;
    for(auto x:nums)
        sum+=x;
    sum/=2;
    vector<vector<long long >> dp(n+1,vector<long long >(sum+1,INT_MAX-2));
    
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=1;i<=sum;i++) dp[0][i] = INT_MAX-2;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=nums[i-1]){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-nums[i-1]]+1);
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    
    if(dp[n][sum]==INT_MAX-2){
        for(int i=0;i<=sum;i++){
            if(dp[n][i]!=INT_MAX-2)
                dp[n][sum] = dp[n][i];
        }
    }
    return dp[n][sum];
}