// Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

// Example :
// Given binary tree

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return

// [
//          [3],
//          [20, 9],
//          [15, 7]
// ]

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
   vector<vector<int>> ans;
   queue<TreeNode*> q;
   int level = 0;
   if(!root) return ans;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       vector<int> row;
       for(int i = 0; i < n; i++){
           TreeNode *curr = q.front();
           q.pop();
           row.push_back(curr->val);
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
       if(level%2)
            reverse(row.begin(), row.end());
        level++;
        ans.push_back(row);
   }
   return ans;
}

