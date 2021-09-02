// Given a binary tree A of integers. Return an array of integers representing
//  the right view of the Binary tree.
// Right view of a Binary Tree: is a set of nodes visible when the tree
// is visited from Right side.

// Problem Constraints
// 1 <= Number of nodes in binary tree <= 105
// 0 <= node values <= 109
// Input Format
// First and only argument is an pointer to the root of binary tree A.

// Output Format
// Return an integer array denoting the right view of the binary tree A.
// Example Input
// Input 1:
//         1
//       /   \
//      2    3
//     / \  / \
//    4   5 6  7
//   /
//  8 
// Input 2:
//     1
//    /  \
//   2    3
//    \
//     4
//      \
//       5

// Example Output
// Output 1:
//  [1, 3, 7, 8]
// Output 2:
//  [1, 3, 4, 5]


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // ITERATIVE
vector<int> Solution::solve(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> ans;
    if(!root)
        return ans;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* curr = q.front();
            q.pop();
            if(i == n-1)
                ans.push_back(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}


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
void rightView(TreeNode* root, vector<int> &ans, int n){
    if(!root) return;
    if(ans.size() == n)
        ans.push_back(root->val);
    rightView(root->right, ans, n+1);
    rightView(root->left, ans, n+1);
} 
 
vector<int> Solution::solve(TreeNode* root) {
    vector<int> ans;
    rightView(root, ans, 0);
    return ans;
}
