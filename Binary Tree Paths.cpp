/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:
Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    void DFS(TreeNode* root, vector<string>& paths, string path = ""){
        if(!root) 
            return;
        // if reached a leaf
        if(!root->left && !root->right){
            path += to_string(root->val);
            paths.push_back(path);
            return;
        } 
        path += to_string(root->val) + "->";
        DFS(root->left,paths,path);
        DFS(root->right,paths,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        DFS(root,paths);
        return paths;
    }
};