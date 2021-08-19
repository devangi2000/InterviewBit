// You are given an array A containing N integers. The special product of each ith integer 
// in this array is defined as the product of the following:
// LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). 
// If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
// RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). 
// If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
// Write a program to find the maximum special product of any integer in the array.
// NOTE: As the answer can be large, output your answer modulo 109 + 7.

// Problem Constraints
// 1 <= N <= 105
// 1 <= A[i] <= 109

// Input Format
// First and only argument is an integer array A.

// Output Format
// Return an integer denoting the maximum special product of any integer.

// Example Input
// Input 1:

//  A = [1, 4, 3, 4]
// Input 2:

//  A = [10, 7, 100]

// Example Output
// Output 1:

//  3
// Output 2:
//  0

// Example Explanation
// Explanation 1:

//  For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
//  So, the ans is 1*3 = 3.
 
// Explanation 2:

//  There is not any integer having maximum special product > 0. So, the ans is 0.

// APPROACH 1:





// APPROACH 2: JUST LOOKS  COMPLICATED
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<long long> prod(A.size());
    prod[0] = 0;
    prod[n-1] = 0;
    
    //Left Greater Element
    stack<pair<int,int>> s;
    s.push({A[0],0});
    for(int i=1;i<n-1;i++){
        while(!s.empty() && s.top().first <= A[i]){
            s.pop();
        }
        if(s.empty()){
            prod[i] = 0;
            s.push({A[i],i});
        }
        else{
            prod[i] = s.top().second;
            s.push({A[i],i});
        }
    }
    
    //Right Greater Element
    stack<pair<int,int>>().swap(s);
    s.push({A[n-1],n-1});
    for(int i=n-2;i>0;i--){
        while(!s.empty() && s.top().first <= A[i]){
            s.pop();
        }
        if(s.empty()){
            prod[i] = 0;
            s.push({A[i],i});
        }
        else{
            if(prod[i] != 0) prod[i] *= s.top().second;
            s.push({A[i],i});
        }
    }

    int index = max_element(prod.begin(),prod.end()) - prod.begin();
    return prod[index] % 1000000007;
}