/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> foward(n,1);
        vector<int> reverse(n,1);
        vector<int> output(n,1);
        
        // fill foward
        foward[0] = nums[0];
        for(int i = 1; i < n; i++)
            foward[i] = foward[i-1] * nums[i]; 
        
        // fill reverse
        reverse[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            reverse[i] = reverse[i+1] * nums[i]; 
        
        // fill output
        output[0] = reverse[1];
        output[n-1] = foward[n-2];
        for(int i = 1; i < n - 1; i++)
            output[i] = foward[i-1] * reverse[i+1];
        
        return output;
    }
};