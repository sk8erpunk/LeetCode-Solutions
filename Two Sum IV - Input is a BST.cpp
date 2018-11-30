/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    
    bool findTargetAux(TreeNode* root, int k, unordered_set<int>& set){
        if(!root) return false;
        if(set.find(k - root->val) != set.end())
            return true;
        else 
            set.insert(root->val);
        
        return findTargetAux(root->left, k, set) || findTargetAux(root->right, k, set);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return findTargetAux(root,k,set);
    }    
    
/* Without using additional space memory */    
//     // Return true if val exist in root
//     bool search(TreeNode* root, int val){
//         if(!root)
//             return false;
//         if(root->val == val)
//             return true;
//         else if(root->val < val)
//             return search(root->right, val);
//         else 
//             return search(root->left, val);
//     }
//     // Return true if two elements with sum k exist
//     bool findTargetAux(TreeNode* node, int k, TreeNode* root) {
//         if(!node)
//             return false;
        
//         int missing_val = k - node->val;
//         bool found = missing_val != node->val ? search(root, missing_val) : false;   // Log(N)
        
//         return found || findTargetAux(node->left, k, root) || findTargetAux(node->right, k, root);

//     }
//     bool findTarget(TreeNode* root, int k) {
//         return findTargetAux(root, k, root);
//     }
};