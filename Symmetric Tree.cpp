/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively
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
    
    void switchSons(TreeNode* root){
        if(root) {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;
            switchSons(root->left);
            switchSons(root->right);
        }
    }
    bool ifSame(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2)
            return true;

        if(!t1 && t2 || t1 && !t2)
            return false;
        
        return (t1->val == t2->val && ifSame(t1->left,t2->left) && ifSame(t1->right,t2->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        switchSons(root->left);
        return ifSame(root->left,root->right);
    }
};