// Given an integer array A of non-negative integers representing an elevation
//  map where the width of each bar is 1, compute how much water it is able to
//  trap after raining.
// Problem Constraints
// 1 <= |A| <= 100000
// Input Format
// The only argument given is integer array A.
// Output Format
// Return the total water it is able to trap after raining.
// Example Input
// Input 1:
//  A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
// Input 2:

//  A = [1, 2]
// Example Output
// Output 1:

//  6
// Output 2:
//  0

// Example Explanation
// Explanation 1:
 
//  In this case, 6 units of rain water (blue section) are being trapped.
// Explanation 2:

//  No water is trapped.

int Solution::trap(const vector<int> &height) {
    vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        maxLeft[0]=height[0];
        //Finding the maximum element on the left and right side of the current ith element for every i
        for(int i=1; i<height.size(); i++){
            maxLeft[i]=max(maxLeft[i-1], height[i]);
        }
        maxRight[height.size()-1]= height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--){
            maxRight[i]=max(height[i], maxRight[i+1]);  
        }
        //Water trapped at every height[i] will be the minimum of the space enclosed by greatest left and right element. We subtract height of the bar from this value.
        vector<int> water(height.size());
        for(int i=0; i<height.size(); i++){
            water[i]=min(maxLeft[i], maxRight[i])-height[i];
        }
        int res=0;
        for(int i=0; i<height.size(); i++){
            res+=water[i];
        }
        return res;
}
