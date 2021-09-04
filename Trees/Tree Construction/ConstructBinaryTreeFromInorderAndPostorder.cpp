// Given inorder and postorder traversal of a tree, construct the binary tree.

//  Note: You may assume that duplicates do not exist in the tree. 
// Example :

// Input : 
//         Inorder : [2, 1, 3]
//         Postorder : [2, 3, 1]

// Return : 
//             1
//            / \
//           2   3


// MY SOLUTION THAT'S UNDERSTANDABLE BUT GIVES MLE

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<int, int> m;
TreeNode* build(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd){
    if(inStart > inEnd or postStart > postEnd) return NULL;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    int inRoot = m[postorder[postEnd]];
    int numsLeft = inRoot - inStart;
    
    root->left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft + 1);
    root->right = build(inorder, inRoot+1, inEnd, postorder, postStart + numsLeft, postEnd -1);
    
    return root;
}


TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
   m.clear();
   if(!inorder.size() or !postorder.size()) return NULL;
   for(int i = 0; i < inorder.size(); i++){
       m[inorder[i]] = i;
   }
   return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

// THIS WORKS

unordered_map<int,int> m;
vector<int> post;
vector<int> in;
TreeNode* build(int inS, int inE, int postS, int postE){
    if(inS>inE||postS>postE)return NULL;
    TreeNode* root = new TreeNode(post[postE]);
    int mid = m[post[postE]];
    root->left = build(inS, mid-1, postS, mid-1-inS+postS);
    root->right= build(mid+1, inE, mid-1-inS+postS+1,postE-1);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    m.clear();post.clear(); in.clear();
    in = inorder; post = postorder;
    for(int i=0;i<in.size();i++) m[in[i]] = i;
    return build(0, in.size()-1, 0, post.size()-1); 
}