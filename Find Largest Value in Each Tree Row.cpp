/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> res;
        list<TreeNode*> queue;
        queue.push_back(root);
        
        while(!queue.empty()){
            int n = queue.size();
            int maxElement = INT_MIN;
            for(int i = 0; i < n; i++){
                TreeNode* curr = queue.front();
                queue.pop_front();
                if(curr->left)
                  queue.push_back(curr->left);
                if(curr->right)
                  queue.push_back(curr->right);
                maxElement = maxElement < curr->val ? curr->val : maxElement; 
            }
            res.push_back(maxElement);
        }
        return res;
    }
};