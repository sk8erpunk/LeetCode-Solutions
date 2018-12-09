/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        list<TreeNode*> queue;
        queue.push_back(root);
        
        while(!queue.empty()){
            int n = queue.size();
            for(int i = 0; i < n; i++){
                TreeNode* p = queue.front();
                if(i == n-1)
                    res.push_back(p->val);
                if(p->left)
                    queue.push_back(p->left);
                if(p->right)
                    queue.push_back(p->right);
                queue.pop_front();
            }
        }
        return res;        
    }
};