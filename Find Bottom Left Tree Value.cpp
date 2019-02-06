/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1

Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> res;
        list<TreeNode*> queue;
        queue.push_back(root);
        
        while(!queue.empty()){
            int n = queue.size();
            vector<int> v;
            for(int i = 0; i < n; i++){
                TreeNode* curr = queue.front();
                queue.pop_front();
                if(curr->left)
                    queue.push_back(curr->left);
                if(curr->right)
                    queue.push_back(curr->right);
                v.push_back(curr->val);
            }
            res.push_back(v);
        }
        return res[res.size()-1][0];
    }
};