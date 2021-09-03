// Find the lowest common ancestor in an unordered binary tree given two values in the tree.

//  Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
// Example :


//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//    6      _2_     0        8
//          /   \
//          7    4
// For the above tree, the LCA of nodes 5 and 1 is 3.

//  LCA = Lowest common ancestor 
// Please note that LCA for nodes 5 and 4 is 5.

// You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
// No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
// There are no duplicate values.
// You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode *LCA(TreeNode *root, int val1, int val2) {
            if (!root) return NULL;
            if (root->val == val1 || root->val == val2) return root;
            TreeNode *L = LCA(root->left, val1, val2);
            TreeNode *R = LCA(root->right, val1, val2);
            if (L && R) return root; // If val1, val2 are on both sides 
            return L ? L : R; // either one of val1, val2 is on one side OR val1, val2 is not in L&R subtrees
        }

        bool find(TreeNode *root, int val1) {
            if (!root) return false;
            if (root->val == val1) return true;
            return (find(root->left, val1) || find(root->right, val1));
        }

        int lca(TreeNode *root, int val1, int val2) {
            if (!find(root, val1) || !find(root, val2)) return -1;
            TreeNode *ans = LCA(root, val1, val2);
            if (!ans) return -1;
            return ans->val;
        }
};