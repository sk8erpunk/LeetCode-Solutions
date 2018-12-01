/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
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
        // In order traversal while saving the last element value each time
        // once we reach a node we calculate the diff between it and last 
        void minDiffInBSTaux(TreeNode* root, int* last, int* currMin) {
            if(root->left)
                minDiffInBSTaux(root->left, last, currMin);
            
            if(*last != INT_MAX) // Not the first element in tree
                *currMin = min(root->val - *last, *currMin);

            *last = root->val;
            if(root->right) 
                minDiffInBSTaux(root->right,last, currMin);
        }
    
        /* Recursive Solution */
        int minDiffInBST(TreeNode* root) {
            int last = INT_MAX;
            int currMin = INT_MAX;
            minDiffInBSTaux(root, &last, &currMin);
            return currMin;
        }    
    
        /* Solution with additional memory space */ 
//         void inOrder(TreeNode* root, vector<int>& arr){
//             if(!root) return;
//             inOrder(root->left,arr);
//             arr.push_back(root->val);
//             inOrder(root->right,arr);
//         }

//         int minDiffInBST(TreeNode* root) {
//             vector<int> arr;
//             inOrder(root, arr);
//             int min_diff = INT_MAX;
//             for(int i = 1; i < arr.size(); i++){
//                 min_diff = min(min_diff, arr[i]-arr[i-1]);
//             }
//             return min_diff;
//         }
};