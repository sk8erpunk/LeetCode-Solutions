/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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
    int minDepth(TreeNode* root){
        if(!root) return 0;
        
        list<TreeNode*> queue;
        queue.push_back(root);
        int level = 1;
        while(!queue.empty()){
            int n = queue.size();    
            for(int i = 0; i < n; i++){
                TreeNode* curr = queue.front();
                queue.pop_front();
                if(!curr->left && !curr->right)    // found first leaf
                    return level;
                if(curr->left)
                    queue.push_back(curr->left);
                if(curr->right)
                    queue.push_back(curr->right);
            }
            level++;
        }
        return 0;
    }
    
};