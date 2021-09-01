// Given a binary tree, return the inorder traversal of its nodes values.

// NOTE: Using recursion is not allowed.



// Problem Constraints
// 1 <= number of nodes <= 105



// Input Format
// First and only argument is root node of the binary tree, A.



// Output Format
// Return an integer array denoting the inorder traversal of the given binary tree.



// Example Input
// Input 1:

//    1
//     \
//      2
//     /
//    3
// Input 2:

//    1
//   / \
//  6   2
//     /
//    3


// Example Output
// Output 1:

//  [1, 3, 2]
// Output 2:

//  [6, 1, 3, 2]


// Example Explanation
// Explanation 1:

//  The Inorder Traversal of the given tree is [1, 3, 2].
// Explanation 2:

//  The Inorder Traversal of the given tree is [6, 1, 3, 2].

// RECURSIVE 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root, vector<int> &ans){
     if(!root) return;
     inorder(root->left, ans);
     ans.push_back(root->val);
     inorder(root->right, ans);
 }
 
 vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    inorder(root, ans);
    return ans;
}

// ITERATIVE

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;

        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
};