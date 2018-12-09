/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        list<TreeNode*> queue;
        queue.push_back(root);
        
        while(!queue.empty()){
            int n = queue.size();
            vector<int> vec;
            for(int i = 0; i < n; i++){
                TreeNode* p = queue.front();
                vec.push_back(p->val);
                if(p->left)
                    queue.push_back(p->left);
                if(p->right)
                    queue.push_back(p->right);
                queue.pop_front();
            }
            res.push_back(vec);
        }
        return res;
    }
};