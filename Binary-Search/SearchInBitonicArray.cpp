// Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.
// NOTE:
// A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

// Problem Constraints
// 3 <= N <= 105

// 1 <= A[i], B <= 108

// Given array always contain a bitonic point.
// Array A always contain distinct elements.

// Input Format
// First argument is an integer array A denoting the bitonic sequence.
// Second argument is an integer B.

// Output Format
// Return a single integer denoting the position (0 index based) of the element
//  B in the array A if B doesn't exist in A return -1.

// Example Input
// Input 1:

//  A = [3, 9, 10, 20, 17, 5, 1]
//  B = 20
// Input 2:

//  A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
//  B = 30

// Example Output
// Output 1:
//  3
// Output 2:
//  -1

// Example Explanation
// Explanation 1:

//  B = 20 present in A at index 3
// Explanation 2:

//  B = 30 is not present in A

int findPeak(vector<int>&v)
{
    int start=0,n=v.size(),end=n-1;
    while(start<=end)
    {
        int mid=start+((end-start)/2);
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1])
        {
            return mid;
        }
        else if(v[mid]>v[mid-1] && v[mid]<v[mid+1])
        {
            start=mid+1;
        }
        else if(v[mid]<v[mid-1] && v[mid]>v[mid+1])
        {
            end=mid-1;
        }
    }
    return n-1;
}

int BinarySearchAscending(vector<int> &A, int start, int end, int el){
    while(start <= end){
        int mid = (start + end) >> 1;
        if(A[mid] == el)
            return mid;
        if(A[mid] > el){
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return -1;
}

int BinarySearchDescending(vector<int> &A, int start, int end, int el){
    while(start <= end){
        int mid = (start + end) >> 1;
        if(A[mid] == el)
            return mid;
        if(A[mid] > el){
            start = mid + 1;
        }
        else end = mid - 1;
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B)
{
    int mid = findPeak(A), n = A.size();
    int asc = BinarySearchAscending(A, 0, mid, B);
    if(asc != -1) return asc;
    return BinarySearchDescending(A, mid+1, n-1, B);
}
