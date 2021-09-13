// Given a binary search tree, write a function to find the kth smallest element in the tree.
// Example :
// Input : 
//   2
//  / \
// 1   3

// and k = 2
// Return : 2
// As 2 is the second smallest element in the tree.
//  NOTE : You may assume 1 <= k <= Total number of nodes in BST 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> inorder;
 
 void getInorder(TreeNode* root){
     if(!root) return;
     getInorder(root->left);
     inorder.push_back(root->val);
     getInorder(root->right);
 }
 
int Solution::kthsmallest(TreeNode* root, int k){
    inorder.clear();
    priority_queue<int> pq;
    getInorder(root);
    for(auto a: inorder){
        pq.push(a);
        if(pq.size() > k)
            pq.pop();
    }
    return pq.top();
}


// OR

void check(TreeNode* a, int &b, int &res){
    if(a == NULL)
        return;
    check(a->left, b, res);
    if(--b == 0){
        res = a->val;
        return;
    }
    if(b > 0)
        check(a->right, b, res);
}

int Solution::kthsmallest(TreeNode* a, int b) {
    if(a == NULL)
        return NULL;
    int res;
    check(a, b, res);
    return res;
}