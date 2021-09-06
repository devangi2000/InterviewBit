// Given a binary tree A with N nodes.
// You have to remove all the half nodes and return the final binary tree.
// NOTE:
// Half nodes are nodes which have only one child.
// Leaves should not be touched as they have both children as NULL.
// Problem Constraints
// 1 <= N <= 105
// Input Format
// First and only argument is an pointer to the root of binary tree A.
// Output Format
// Return a pointer to the root of the new binary tree.

// Example Input
// Input 1:

//            1
//          /   \
//         2     3
//        / 
//       4

// Input 2:

//             1
//           /   \
//          2     3
//         / \     \
//        4   5     6

// Example Output
// Output 1:
//            1
//          /   \
//         4     3
// Output 2:

//             1
//           /   \
//          2     6
//         / \

//        4   5

// Example Explanation
// Explanation 1:
//  The only half node present in the tree is 2 so we will remove this node.
// Explanation 2:
//  The only half node present in the tree is 3 so we will remove this node.

/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    public TreeNode solve(TreeNode root){
        if(root == null) return root;
        if(root.left == null && root.right == null) return root;
        if(root.left == null) return solve(root.right);
        if(root.right == null) return solve(root.left);
        root.left = solve(root.left);
        root.right = solve(root.right);
        return root;
    }
}
