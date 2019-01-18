/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void dfs(TreeNode* root, int sum, vector<vector<int>>& paths, vector<int>& p){
        if(!root)  
            return; 

        p.push_back(root->val);
        sum -= root->val;
        if(!root->left && !root->right && sum == 0) // if reached a path
            paths.push_back(p);
       
        dfs(root->left, sum, paths, p);
        dfs(root->right, sum, paths, p);
        p.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> p;
        dfs(root, sum, paths, p);
        return paths;
    }
};