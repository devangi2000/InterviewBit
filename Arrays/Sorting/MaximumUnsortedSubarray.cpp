// You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
// Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
// If A is already sorted, output -1.

// Example :

// Input 1:

// A = [1, 3, 2, 4, 5]

// Return: [1, 2]

// Input 2:

// A = [1, 2, 3, 4, 5]

// Return: [-1]
// In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size(), start = -1, end = -1;
    for(int i = 0; i < n-1; i++){
        if(A[i] > A[i+1]){
            start = i;
            break;
        }
    }
    if(start == -1) return {-1};
    
    for(int i = n-1; i > 0; i--){
        if(A[i-1] > A[i]){
            end = i;
            break;
        }
    }
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = start; i <= end; i++){
        mini = min(mini, A[i]);
        maxi = max(maxi, A[i]);
    }
    for(int i = 0; i < start; i++){
        if(A[i] > mini){
            start = i;
            break;
        }
    }
    for(int j = n-1; j > end; j--){
        if(A[j] < maxi){
            end = j;
            break;
        }
    }
    return {start, end};
}
