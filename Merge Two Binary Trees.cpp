/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  

Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) 
            return NULL;
        int sum = 0;
        if(t1) 
            sum += t1->val;
        if(t2)
            sum += t2->val;
        TreeNode* sumNode = new TreeNode(sum);
        sumNode->left = mergeTrees(t1 != NULL? t1->left : NULL, t2 != NULL? t2->left : NULL);
        sumNode->right = mergeTrees(t1 != NULL? t1->right : NULL, t2 != NULL? t2->right : NULL);
        return sumNode;
    }
};