// Given a Binary Tree A consisting of N nodes.

// You need to find all the cousins of node B.

// NOTE:

// Siblings should not be considered as cousins.
// Try to do it in single traversal.
// You can assume that Node B is there in the tree A.
// Order doesn't matter in the output.


// Problem Constraints
// 1 <= N <= 105

// 1 <= B <= N



// Input Format
// First Argument represents the root of binary tree A.

// Second Argument is an integer B denoting the node number.



// Output Format
// Return an integer array denoting the cousins of node B.

// NOTE: Order doesn't matter.



// Example Input
// Input 1:

//  A =

//            1
//          /   \
//         2     3
//        / \   / \
//       4   5 6   7 


// B = 5

// Input 2:

//  A = 
//             1
//           /   \
//          2     3
//         / \ .   \
//        4   5 .   6


// B = 1




// Example Output
// Output 1:

//  [6, 7]
// Output 2:

//  []


// Example Explanation
// Explanation 1:

//  Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
//  Remember Node 4 is sibling of Node 5 and do not need to return this.
// Explanation 2:

//  Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int node) {
   if(!root or root->val == node) return {};
   bool found = 0;
   queue<TreeNode*> q;
   q.push(root);
   while(q.size() and !found){
       int n = q.size();
       for(int i = 0; i < n; i++){
           TreeNode* curr = q.front();
           if(curr->right and curr->right->val == node or (curr->left and curr->left->val == node))
                found = 1;
           else{
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
           }
           q.pop();
       }
   }
   vector<int> ans;
   while(q.size()){
       ans.push_back(q.front()->val);
       q.pop();
   }
   return ans;
}


