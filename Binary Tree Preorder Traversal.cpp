/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> stack;
        vector<int> res;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* curr = stack.top();
            stack.pop();
            res.push_back(curr->val);
            if(curr->right)
                stack.push(curr->right);
            if(curr->left)
                stack.push(curr->left);
        }
        return res;
    }
};