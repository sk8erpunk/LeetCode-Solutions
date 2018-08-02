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
        set<vector<int>> sol;
        
        if(nums.empty() || nums.size() < 4){
            vector<vector<int>> empty;
            return empty;
        }
     
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 3; i++){
            for(int j = i + 1; j < nums.size() - 2; j++){
                int l = j + 1, h = nums.size() - 1;
                while(l < h){
                    if(nums[l] + nums[h] + nums[i] + nums[j] == target){
                        vector<int> s;
                        s.push_back(nums[i]);
                        s.push_back(nums[j]);
                        s.push_back(nums[l]);
                        s.push_back(nums[h]);
                        sol.insert(s);
                        l++;
                    }
                    if(nums[l] + nums[h] + nums[i] + nums[j] < target){
                        l++;
                    }
                    if(nums[l] + nums[h] + nums[i] + nums[j] > target){
                        h--;
                    }
                }
            }
        }
        vector<vector<int>> solution(sol.begin(),sol.end());
        return solution;
    }
};