// There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.
// The cost of painting each house with a certain color is different. You have to paint all
// the houses such that no two adjacent houses have the same color.
// The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.
// For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of
// painting house 1 with color green, and so on.
// Find the minimum total cost to paint all houses.

// Problem Constraints
// 1 <= N <= 105
// 1 <= A[i][j] <= 103

// Input Format
// First and only argument is an 2D integer matrix A of size N x 3 denoting the cost to paint the houses.
// Output Format
// Return an integer denoting the minimum total cost to paint all houses.
// Example Input
// Input 1:

//  A = [  [1, 2, 3]
//         [10, 11, 12]
//      ]

// Example Output
// Output 1:

//  12
// Example Explanation
// Explanation 1:

//  Paint house 1 with red and house 2 with green i.e A[0][0] + A[1][1] = 1 + 11 = 12

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), cost = 0, i = 0;
    if(n == 0) return 0;
    for(i = 1; i < n; ++i){
        A[i][0] += min(A[i-1][1], A[i-1][2]);
        A[i][1] += min(A[i-1][0], A[i-1][2]);
        A[i][2] += min(A[i-1][0], A[i-1][1]);
    }
    cost = min({A[i-1][0], A[i-1][1], A[i-1][2]});
    return cost;
}
