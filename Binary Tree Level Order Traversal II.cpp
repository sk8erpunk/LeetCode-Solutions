/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {}; 
        vector<vector<int>> res;
        list<TreeNode*> queue;
        queue.push_back(root);
        while(!queue.empty()){
            vector<int> v;
            int n = queue.size();
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
        reverse(res.begin(), res.end());
        return res;
    }
};