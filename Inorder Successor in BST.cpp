/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.

Example 1:
Input: root = [2,1,3], p = 1

  2
 / \
1   3

Output: 2

Example 2:
Input: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

Output: null
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
    unordered_map<TreeNode*,TreeNode*> parent;
    
    void findParents(TreeNode* p, TreeNode* n){
        parent[n] = p;
        if(n->left)
            findParents(n, n->left);
        if(n->right)
            findParents(n, n->right);
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return NULL;
        findParents(NULL,root);    
        TreeNode* itr = p;
        if(itr->right){
            itr = itr->right;
            while(itr->left)
                itr = itr->left;
            return itr;
        } else {
            while(parent[itr] && parent[itr]->right == itr)
                itr = parent[itr];
            return parent[itr];
        }
    }
};