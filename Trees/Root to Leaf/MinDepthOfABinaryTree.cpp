// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the
//  root node down to the nearest leaf node.
//  NOTE : The path has to end on a leaf node. 
// Example :

//          1
//         /
//        2
// min depth = 2.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* root) {
    // base condition
    if(!root) return 0;
    // leaf node
    if(!root->left && !root->right) return 1;
    //no left side
    if(!root->left) return 1+minDepth(root->right);
    // no right side
    if(!root->right) return 1+minDepth(root->left);
    
    return 1+min(minDepth(root->left), minDepth(root->right));
}
