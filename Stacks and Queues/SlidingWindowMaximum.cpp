// Given an array of integers A. There is a sliding window of size B which
// is moving from the very left of the array to the very right.
// You can only see the w numbers in the window. Each time the sliding window moves
// rightwards by one position. You have to find the maximum for each window.
// The following example will give you more clarity.

// The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

// Window position	Max
// ———————————-	————————-
// [1 3 -1] -3 5 3 6 7	3
// 1 [3 -1 -3] 5 3 6 7	3
// 1 3 [-1 -3 5] 3 6 7	5
// 1 3 -1 [-3 5 3] 6 7	5
// 1 3 -1 -3 [5 3 6] 7	6
// 1 3 -1 -3 5 [3 6 7]	7
// Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

// Note: If B > length of the array, return 1 element with the max of the array.

// Input Format

// The first argument given is the integer array A.
// The second argument given is the integer B.
// Output Format

// Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]
// For Example

// Input 1:
//     A = [1, 3, -1, -3, 5, 3, 6, 7]
//     B = 3
// Output 1:
//     C = [3, 3, 5, 5, 6, 7]


// APPROACH 1
vector<int> Solution::slidingMaximum(const vector<int> &A, int w) {
    vector<int> ans;
    deque<int> dq;
    int n = A.size(), start = 0, end = 0;
    while(end < n){
        while(!dq.empty() and A[end] > dq.back())
            dq.pop_back();
        dq.push_back(A[end]);
        if(end - start + 1 < w)
            end++;
        else if(end - start + 1 == w){
            ans.push_back(dq.front());
            if(dq.front() == A[start])
                dq.pop_front();
            end++;
            start++;
        }
    }
    return ans;
}


// APPROACH 2
vector<int> Solution::slidingMaximum(const vector<int> &A, int w) {
    vector<int> B;
    deque<int> dq;
    int n=A.size();
    B.resize(n-w+1);
    for(int i=0;i<w;i++)
    {
        while(!dq.empty() && A[i]>=A[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    for(int i=w; i<n; i++)
    {
        B[i-w] = A[dq.front()];
        while(!dq.empty() && A[i]>=A[dq.back()]) dq.pop_back();
        while(!dq.empty() && dq.front()<= i-w) dq.pop_front();
        dq.push_back(i);
    }
    B[n-w]=A[dq.front()];
    return B;
}