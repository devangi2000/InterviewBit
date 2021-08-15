// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

//  A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
// Example :


// Given A : 1 -> 2 -> 3
// A height balanced BST  :

//       2
//     /   \
//    1     3

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* head) {
    if(!head) return NULL;
    if(!head->next) return new TreeNode(head->val);
    ListNode *slow = head, *fast = head->next;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = NULL;
    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    return root;
}
