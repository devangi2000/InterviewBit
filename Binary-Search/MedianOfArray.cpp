// There are two sorted arrays A and B of size m and n respectively.
// Find the median of the two sorted arrays ( The median of the array 
// formed by merging both the arrays ).
// The overall run time complexity should be O(log (m+n)).
// Sample Input
// A : [1 4 5]
// B : [2 3]

// Sample Output

// 3
//  NOTE: IF the number of elements in the merged array is even, then the median 
// is the average of n / 2 th and n/2 + 1th element.
// For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if(B.size() < A.size()) return findMedianSortedArrays(B, A);
    int n1 = A.size(), n2 = B.size(), cut1 = 0, cut2 = 0, l1 = 0, l2 = 0, r1 = 0, r2 = 0;
    int low = 0, high = n1;
    while(low <= high){
        cut1 = low + (high - low) / 2;
        cut2 = (n1 + n2 + 1)/2 - cut1;
        l1 = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
        l2 = (cut2 == 0) ? INT_MIN : B[cut2 - 1];
        r1 = (cut1 == n1) ? INT_MAX : A[cut1];
        r2 = (cut2 == n2) ? INT_MAX : B[cut2];
        if(l1 <= r2 and l2 <= r1){
            if((n1 + n2)%2 == 0)
                return (max(l1, l2) + min(r1, r2))/2.0;
            else
                return(max(l1, l2));
        }
        else if(l1 > r2){
            high = cut1 - 1;
        }
        else
            low = cut1 + 1;
    }
    return 0.0;
}
 