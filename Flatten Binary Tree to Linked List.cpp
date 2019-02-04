/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    
    void preOrder(TreeNode* root, vector<TreeNode*>& nodes){
        if(root) {
            nodes.push_back(root);
            preOrder(root->left, nodes);
            preOrder(root->right, nodes);
        }
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        preOrder(root, nodes);
        TreeNode* curr = root;
        for(int i = 1; i < nodes.size(); i++){
            curr->left = NULL;
            curr->right = nodes[i];
            curr = curr->right;
        }
    }
};