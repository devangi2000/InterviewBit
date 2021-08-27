// Given a positive integer n and a string s consisting only of letters D or I, you
//  have to find any permutation of first n positive integer that satisfy the given input string.
// D means the next number is smaller, while I means the next number is greater.

// Notes

// Length of given string s will always equal to n - 1
// Your solution should run in linear time and space.
// Example :

// Input 1:

// n = 3

// s = ID

// Return: [1, 3, 2]

vector<int> Solution::nextPermutation(vector<int> &A) {
    next_permutation(A.begin(), A.end());
    return A;
}


// OR

    vector<int> Solution::nextPermutation(vector<int> &nums) {
    int n = nums.size(), breakpoint=-1, j;
    // find the first index from the end where num[i] < num[i+1]; call this breakpoint
    for(int i = n-1; i > 0; i--){
        if(nums[i-1] < nums[i]){
            breakpoint = i-1;
            break;
        }
    }
    // edge case 1
    if(breakpoint == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    }
    // find the first number from the end which is JUST greater than nums[breakpoint]; 
    // call this j
    for(j = n-1; j >= 0; j--){
        if(nums[j] > nums[breakpoint]){
            break;
        }
    }
        // swap breakpoint and j
    swap(nums[breakpoint], nums[j]);
    // reverse all elements from breakpoint till the end
    reverse(nums.begin() + breakpoint + 1, nums.end());
    
    return nums;
}