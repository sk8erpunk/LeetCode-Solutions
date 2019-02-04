/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

Note:
The size of the given array will be in the range [1,1000].
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
    
    int findMaxIndex(vector<int>& nums, int start, int end){
        int maxIdx = start;
        for(int i = start; i <= end; i++)
            maxIdx = nums[i] > nums[maxIdx] ? i : maxIdx;
        return maxIdx;
    }
    
    TreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start > end)
            return NULL;
        
        int idx = findMaxIndex(nums, start, end);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = buildTree(nums, start, idx-1);
        root->right = buildTree(nums, idx+1, end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};