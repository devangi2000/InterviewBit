// Two elements of a binary search tree (BST) are swapped by mistake.
// Tell us the 2 values swapping which the tree will be restored.

//  Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
// Example :


// Input : 
//          1
//         / \
//        2   3

// Output : 
//        [1, 2]

// Explanation : Swapping 1 and 2 will change the BST to be 
//          2
//         / \
//        1   3
// which is a valid BST 


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> MorrisTraversal(TreeNode *root, TreeNode *first, TreeNode *last, TreeNode *pre)
{
    //first is the pointer where the mismatch began. (In inorder traversal of a BST, we get ascending order.
    //Wherever this ascending order breaks its mismatch)
    //last is the last trace of mismatch.
    //pre is the pointer of lastly printed node

    //This works by finding out the inorder successor of every element and using them to go to the next node
    TreeNode *current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {

            //Checking if there is a mismatch. 
            //Note that this check happens everytime we print value. 
            if (first == NULL && pre != NULL && pre->val > current->val)
            {
                //If first ==NULL it means that we this is the first time mismatch is found
                //So we assign this to first
                first = pre;
                last = current;
            }
            else if (first != NULL && pre != NULL && pre->val > current->val)
            {
                //If first is not null it means that mismatch has started earlier.
                //We only need to update the last pointer
                last = current;
            }
            pre = current; //updating the pre everytime we print



            //If you dont find any element smaller than current,
            //cout<<current->val<<" "; //You are at a position where you can print the element as it is the smallest elemnt
            current = current->right; //in the elements that are remaining.
        }
        else
        {
            TreeNode *prev = current->left; //If the left is not empty, there are elements smaller than this
            //But before going there, we shall find out the inorder predecessor to this element

            //Finding the inorder predecessor of current

            while (prev->right != NULL && prev->right != current)
            {
                //If prev->right==NULL it means you are at the maximum element on the left subtree of current
                //If prev->right ==current it means that this element is the greatest element smaller than the current element.
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                //So if you are the maximum element on the left subtree of current,
                //it means that you are the inorder predecessor of current
                //Assign current as the right pointer of the inorder successor
                prev->right = current;
                current = current->left; //And like mentioned in line 93 lets go to further left and find out about the other elements
            }
            else
            {
                if (first == NULL && pre != NULL && pre->val > current->val)
                {
                    first = pre;
                    last = current;
                }
                else if (first != NULL && pre != NULL && pre->val > current->val)
                {
                    last = current;
                }
                pre = current;
                //If you are the greatest element smaller than current, it means you can safely print it now.
                //That is because you are going to as left as possible and printing the smallest elements on line 64.
                //After they are done the next smallest element will be the element that has some left pointers but all of which are already printed.
                prev->right = NULL;
                //cout<<current->val<<" ";
                current = current->right;
            }
        }
    }
    vector<int> v;
    v.push_back(min(first->val,last->val));
    v.push_back(max(first->val,last->val));
    return v;
}
vector<int> Solution::recoverTree(TreeNode* A) {
    return MorrisTraversal(A,NULL,NULL,NULL);

}