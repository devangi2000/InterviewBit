// Given an index k, return the kth row of the Pascal's triangle.
// Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.
// Example:
// Input : k = 3
// Return : [1,3,3,1]
// Note: k is 0 based. k = 0, corresponds to the row [1].
// Note: Could you optimize your algorithm to use only O(k) extra space?


vector<int> Solution::getRow(int k) {
    vector<int> ans;
    long long num = 1;
    ans.push_back(num);
    for(int i = 1; i <= k; i++){
        num *= (k-i+1);
        num /= i;
        ans.push_back(num);
    }
    return ans;
}