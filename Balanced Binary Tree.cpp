/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:
Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int treeHeight(TreeNode* root){
        if(!root)
            return 0;       

        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        
        if(left == INT_MIN || right == INT_MIN)     // Pass up error code 
            return INT_MIN;
        
        if(abs(left - right) > 1)                   // Error case 
            return INT_MIN;

        return max(left,right) + 1;                 // Return new height
    }
    
    bool isBalanced(TreeNode* root) {
        return treeHeight(root) != INT_MIN;         // True if no error code 
    }
};