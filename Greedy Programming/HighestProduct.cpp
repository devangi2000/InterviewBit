// Given an array A, of N integers A.
// Return the highest product possible by multiplying 3 numbers from the array.
// NOTE: Solution will fit in a 32-bit signed integer.

// Input Format:

// The first and the only argument is an integer array A.

// Output Format:

// Return the highest possible product.

// Constraints:

// 1 <= N <= 5e5

// Example:

// Input 1:
// A = [1, 2, 3, 4]

// Output 1:
// 24

// Explanation 1:
// 2 * 3 * 4 = 24

// Input 2:
// A = [0, -1, 3, 100, 70, 50]

// Output 2:
// 350000

// Explanation 2:
// 70 * 50 * 100 = 350000

// DON'T DO THIS IN AN INTERVIEW: It takes O(nlogn) TC

int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    if(n < 3) return 0;
    sort(A.begin(), A.end());
    return max(A[n-1] * A[n-2] * A[n-3], A[0] * A[1] * A[n-1]);
}

// DO THIS: It has Linear, ie, O(N) TC

int Solution::maxp3(vector<int> &arr) {
    int n = arr.size();
    if(n < 3)
        return 0;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN,
        min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2){
            max3 = max2;
            max2 = arr[i];
        }
        else if(arr[i] > max3)
            max3 = arr[i];
        if(arr[i] < min1){
            min2 = min1;
            min1 = arr[i];
        }
        else if(arr[i] < min2)
            min2 = arr[i];
    }
    return max(max1*max2*max3 , min1*min2*max1);
}

  