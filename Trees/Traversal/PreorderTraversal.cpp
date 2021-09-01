// Given a binary tree, return the preorder traversal of its nodes’ values.

// Example :
// Given binary tree

//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//  WITHOUT RECURSION
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode*> nodeStack;

            while (nodeStack.size() != 0 || root != NULL) {
                if(root == NULL) {
                    root = nodeStack.top();
                    nodeStack.pop();
                } else {
                    res.push_back(root->val);
                    if(root->right != NULL)
                        nodeStack.push(root->right);
                    root = root->left;
                }
            }
            return res;
        }
};

// WITH RECURSION
 void preorder(TreeNode* root, vector<int> &pre){
     if(!root) return;
     pre.push_back(root->val);
     preorder(root->left, pre);
     preorder(root->right, pre);
 }
 
 vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int> pre;
    if(!root) return pre;
    preorder(root, pre);
    return pre;
}

