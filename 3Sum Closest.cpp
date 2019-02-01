/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) 
            return 0;
    
        sort(nums.begin(), nums.end()); 
        
        int closest = nums[0] + nums[1] + nums[nums.size()-1];
        for(int i = 0; i < nums.size() - 2; i++){
            int low = i + 1;
            int high = nums.size() - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                closest = abs(sum - target) < abs(closest - target) ? sum : closest;
                if (sum < target){
                    low++;
                } else if(sum > target) {
                    high--;
                } else {
                    return target;
                }
            }
        }
        return closest;           
    }
};
