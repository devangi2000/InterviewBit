// Find the contiguous subarray within an array, A of length N which has the largest sum.

// Input Format:

// The first and the only argument contains an integer array, A.
// Output Format:

// Return an integer representing the maximum possible sum of the contiguous subarray.
// Constraints:

// 1 <= N <= 1e6
// -1000 <= A[i] <= 1000
// For example:

// Input 1:
//     A = [1, 2, 3, 4, -10]

// Output 1:
//     10

// Explanation 1:
//     The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

// Input 2:
//     A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

// Output 2:
//     6

// Explanation 2:
//     The subarray [4,-1,2,1] has the maximum possible sum of 6.

int Solution::maxSubArray(const vector<int> &A) {
    int max_so_far = INT_MIN, max_end = 0;
    for(int i=0; i<A.size(); i++)
    {
        max_end = max_end + A[i];
        if(max_so_far<max_end)max_so_far=max_end;
        if(max_end<0)max_end=0;
    } return max_so_far;
}

// OR (Same thing only )
int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size(), maxsum = 0, maxsofar = INT_MIN;
    for(int i = 0; i < n; i++){
        maxsum += A[i];
        maxsofar = (maxsofar < maxsum) ? maxsum : maxsofar;
        maxsum = max(maxsum, 0);
    }
    return maxsofar;
}