// int Solution::solve(vector<int> &A) {
//     int l = 0;
//     int n =A.size();
//     int r = n-1;
//     while(l<=r){
//         int mid = l+(r-l)/2;
//         if(mid>0 and mid<n-1){
//             if(A[mid]>=A[mid-1] and A[mid]>=A[mid+1])
//                 return A[mid];
//             else if(A[mid]>=A[mid-1] and A[mid]<=A[mid+1])
//                 l = mid+1;
//             else if(A[mid]<=A[mid-1] and A[mid]>=A[mid+1])
//                 r = mid-1;
//         }
//         else
//             break;
//     }
//     if(A[0]>A[n-1])
//         return A[0];
//     return A[n-1];
// }
