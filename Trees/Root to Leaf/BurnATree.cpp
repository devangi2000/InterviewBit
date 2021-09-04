// Given a binary tree denoted by root node A and a leaf node B from this tree.
// It is known that all nodes connected to a given node (left child, right child and
//  parent) get burned in 1 second. Then all the nodes which are connected through one
//   intermediate get burned in 2 seconds, and so on.
// You need to find the minimum time required to burn the complete binary tree.

// Problem Constraints
// 2 <= number of nodes <= 105
// 1 <= node value, B <= 105
// node value will be distinct

// Input Format
// First argument is a root node of the binary tree, A.
// Second argument is an integer B denoting the node value of leaf node.

// Output Format
// Return an integer denoting the minimum time required to burn the complete binary tree.

// Example Input
// Input 1:

//  Tree :      1 
//             / \ 
//            2   3 
//           /   / \
//          4   5   6
//  B = 4
// Input 2:

//  Tree :      1
//             / \
//            2   3
//           /     \
//          4       5 
//  B = 5 


// Example Output
// Output 1:

//  4
// Output 2:
//  4

// Example Explanation
// Explanation 1:

//  After 1 sec: Node 4 and 2 will be burnt. 
//  After 2 sec: Node 4, 2, 1 will be burnt.
//  After 3 sec: Node 4, 2, 1, 3 will be burnt.
//  After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.
 
// Explanation 2:

//  After 1 sec: Node 5 and 3 will be burnt. 
//  After 2 sec: Node 5, 3, 1 will be burnt.
//  After 3 sec: Node 5, 3, 1, 2 will be burnt.
//  After 4 sec: Node 5, 3, 1, 2, 4(whole tree) will be burnt.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* root, int begin){
    if(!root) return 0;
    map<TreeNode*, TreeNode*> parent;
    map<TreeNode*, int> visited;
    queue<TreeNode*> q;
    q.push(root);
    parent.insert({root, root});;
    visited.insert({root, 0});
    TreeNode* start = NULL;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == begin){
                start = curr;
            }
            if(curr->left){
                parent[curr->left] = curr;
                visited[curr->left] = 0;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                visited[curr->right] = 0;
                q.push(curr->right);
            }
        }    
    }
    q.push(start);
    int times = 0;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            TreeNode* curr = q.front();
            q.pop();
            if(!visited[curr]){
                if(curr->left and !visited[curr->left])
                    q.push(curr->left);
                if(curr->right and !visited[curr->right])
                    q.push(curr->right);
                if(parent[curr] != curr and !visited[parent[curr]])
                    q.push(parent[curr]);
            }
            visited[curr] = 1;
        }
        times++;
    }
    return times-1;
}