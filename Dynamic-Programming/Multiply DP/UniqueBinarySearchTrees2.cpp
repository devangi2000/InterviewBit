// Given an integer A, how many structurally unique BST’s (binary search trees) exist that can
//  store values 1…A?
// Input Format:
// The first and the only argument of input contains the integer, A.
// Output Format:
// Return an integer, representing the answer asked in problem statement.
// Constraints:
// 1 <= A <= 18
// Example:
// Input 1:
//     A = 3
// Output 1:
//     5
// Explanation 1:
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

int Solution::numTrees(int n) {
    vector<int> catalan(n+1);
    catalan[0] = 1;
    catalan[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j< i; j++){
            catalan[i] += catalan[j] * catalan[i-j-1];
        }
    }
    return catalan[n];
}