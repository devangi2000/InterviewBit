// Given an unsorted integer array, find the first missing positive integer.

// Example:

// Given [1,2,0] return 3,

// [3,4,-1,1] return 2,

// [-8, -7, -6] returns 1

// Your algorithm should run in O(n) time and use constant space.

int Solution::firstMissingPositive(vector<int> &nums){
    int n = nums.size(), i = 0;
        while(i < n){
            if(nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for(int i=0; i<n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
}
