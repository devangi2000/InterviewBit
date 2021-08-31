// Given a binary tree T, find the maximum path sum.

// The path may start and end at any node in the tree.

// Input Format:

// The first and the only argument contains a pointer to the root of T, A.
// Output Format:

// Return an integer representing the maximum sum path.
// Constraints:

// 1 <= Number of Nodes <= 7e4
// -1000 <= Value of Node in T <= 1000
// Example :

// Input 1:

//        1
//       / \
//      2   3

// Output 1:
//      6

// Explanation 1:
//     The path with maximum sum is: 2 -> 1 -> 3

// Input 2:
    
//        -10
//        /  \
//      -20  -30

// Output 2:
//     -10

// Explanation 2
//     The path with maximum sum is: -10

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* root, int &maxi){
    if(!root) return 0;
    int left = max(0, solve(root->left, maxi));
    int right = max(0, solve(root->right, maxi));
    maxi = max(maxi, root->val + left + right);
    return root->val + max(left, right);
}
 

int Solution::maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}
