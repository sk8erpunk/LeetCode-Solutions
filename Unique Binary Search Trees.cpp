/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:
Input: 3
Output: 5

Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        vector<int> memo(n+1,0);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2; i < n+1; i++) {
            for(int j = 1; j <= i; j++){
                int left = memo[j-1] > 0 ? memo[j-1] : 1;
                int right = memo[i-j] > 0 ? memo[i-j] : 1;
                memo[i] += left*right;
            }
        }
        return memo[n];
    }
};