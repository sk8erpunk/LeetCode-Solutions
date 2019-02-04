/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    
    int findRootIdx(vector<int>& inorder, int root, int start, int end){
        for(int i = start; i <= end; i++){
            if(inorder[i] == root)
                return i;
        }
        return -1;
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int* idx){
        if(start > end)
            return NULL;
        int rootPO = preorder[*idx];
        *idx += 1;
        int rootIOidx = findRootIdx(inorder, rootPO, start, end);
        TreeNode* root = new TreeNode(rootPO);
        root->left = build(preorder, inorder, start, rootIOidx-1, idx);
        root->right = build(preorder, inorder, rootIOidx+1, end, idx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idxRoot = 0;
        return build(preorder, inorder, 0, inorder.size()-1, &idxRoot);
    }
};