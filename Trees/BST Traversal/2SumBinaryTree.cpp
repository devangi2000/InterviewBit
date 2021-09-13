// Given a binary search tree A, where each node contains a positive integer, and an integer B, 
// you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.
// Return 1 to denote that two such nodes exist. Return 0, otherwise.

// Problem Constraints
// 1 <= size of tree <= 100000
// 1 <= B <= 109

// Input Format
// First argument is the head of the tree A.
// Second argument is the integer B.

// Output Format
// Return 1 if such a pair can be found, 0 otherwise.

// Example Input
// Input 1:

//          10
//          / \
//         9   20
// B = 19
// Input 2: 
//           10
//          / \
//         9   20

// B = 40

// Example Output
// Output 1:
//  1
// Output 2:
//  0
// Example Explanation
// Explanation 1:

//  10 + 9 = 19. Hence 1 is returned.
// Explanation 2:

//  No such pair exists.


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
int Solution::t2Sum(TreeNode* root, int target){
    inorder.clear();
    getInorder(root);
    int start = 0, end = inorder.size()-1;
    while(start < end){
        if(inorder[start] + inorder[end] == target)
            return 1;
        else if(inorder[start] + inorder[end] < target)
            start++;
        else end--;
    }
    return 0;
}
