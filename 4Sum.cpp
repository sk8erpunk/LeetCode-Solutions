/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        if(nums.empty() || nums.size() < 4) return {};
     
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int l = j + 1, h = nums.size() - 1;
                while(l < h){
                    int sum = nums[l] + nums[h] + nums[i] + nums[j];
                    if(sum == target){
                        res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[h]});
                        while(l < h && nums[l] == nums[l+1]) l++;
                        while(l < h && nums[h] == nums[h-1]) h--;    
                        l++;
                        h--;
                    } else if(sum < target){
                        l++;
                    } else {
                        h--;
                    }
                }
            }
        }
        return res;
    }
};