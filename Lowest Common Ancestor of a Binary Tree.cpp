/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

		 
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
             according to the LCA definition.

Note:
All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

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
    // Find parent for each node 
    void findParent(TreeNode* parent, TreeNode* node, unordered_map<TreeNode*,TreeNode*>& map){
        if(node){
            findParent(node,node->left,map);
            findParent(node,node->right,map);
            map[node] = parent;
        }
    }
    
    // Find node depth 
    int findDepth(TreeNode* root, TreeNode* p){
        if(root == NULL)
            return INT_MAX;
        if(root == p)
            return 0;
        int dl = findDepth(root->left,p);
        dl = dl == INT_MAX ? INT_MAX : dl + 1;
        int dr = findDepth(root->right,p);
        dr = dr == INT_MAX ? INT_MAX : dr + 1;
        return min(dl,dr);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return NULL;
        unordered_map<TreeNode*,TreeNode*> parent;
        findParent(NULL,root,parent); // find parent of each node 
        int dp = findDepth(root,p);
        int dq = findDepth(root,q);
        TreeNode* deeper = dp > dq ? p : q;
        TreeNode* closer = dp > dq ? q : p;
        int delta = abs(dp - dq);
        while(delta){
            deeper = parent[deeper];
            delta--;
        }
        while(deeper != closer){
            deeper = parent[deeper];
            closer = parent[closer];
        }
        return deeper;
    }
};