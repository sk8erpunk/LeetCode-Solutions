/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:
1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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

    void setPathCount(unordered_map<int,int>& countPathsMap, int runningSum, int val){
        int pc = countPathsMap.count(runningSum) ? countPathsMap[runningSum] : 0;
        pc += val;
        if(pc == 0)	
            countPathsMap.erase(runningSum); 
        else
            countPathsMap[runningSum] = pc; 
    }

    int countPaths(TreeNode* root, int targetSum, int runningSum, unordered_map<int,int>& countPathsMap){
        if(!root) 
            return 0;
        runningSum += root->val; 
        int totalPaths = countPathsMap.count(runningSum - targetSum) ? countPathsMap[runningSum - targetSum] : 0; 
        if(runningSum == targetSum)
            totalPaths++;
        setPathCount(countPathsMap, runningSum ,1);
        totalPaths += countPaths(root->left, targetSum, runningSum, countPathsMap);
        totalPaths += countPaths(root->right, targetSum, runningSum, countPathsMap);
        setPathCount(countPathsMap, runningSum, -1);
        return totalPaths;
    }

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> countPathsMap;
	    return countPaths(root, sum, 0, countPathsMap);
    }
};