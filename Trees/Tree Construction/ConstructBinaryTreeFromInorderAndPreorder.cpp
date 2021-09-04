// Given preorder and inorder traversal of a tree, construct the binary tree.

//  Note: You may assume that duplicates do not exist in the tree. 
// Example :

// Input :
//         Preorder : [1, 2, 3]
//         Inorder  : [2, 1, 3]

// Return :
//             1
//            / \
//           2   3


// MY CODE GIVES MLE

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* getTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder,
                    int inStart, int inEnd, map<int, int> mp){
    if(preStart > preEnd or inStart > inStart)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);
    if(preEnd == preStart) return root;
    int inRoot = mp[root->val];
    int numsLeft = inRoot - inStart;
    root->left = getTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mp);
    root->right = getTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot+1, inEnd, mp);
    return root;
} 
 
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    map<int, int> mp;
    for(int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;
    return getTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size()-1, mp);
}

// EDITORIAL

TreeNode * build(vector<int> &pre, int &preIdx,unordered_map<int,int> &m,int start,int end){
    if(start>end) return NULL;
    TreeNode *root = new TreeNode(pre[preIdx++]);
    if(start == end) return root;
    root->left = build(pre,preIdx,m,start,m[root->val]-1);
    root->right = build(pre,preIdx,m,m[root->val]+1,end);
    return root;
 }
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
    unordered_map<int,int> mp;
    for(int i=0; i<in.size(); i++) mp[in[i]] = i;
    int n=0;
    return build(pre,n,mp,0,in.size()-1);
}
