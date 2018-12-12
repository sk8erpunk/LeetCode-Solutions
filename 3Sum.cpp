/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
    
        sort(nums.begin(), nums.end()); 
        
        int low,high,sum;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                low = i + 1;
                high = nums.size() - 1;
                sum = 0 - nums[i];
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        vector<int> v(3,0);
                        v[0] = nums[i];
                        v[1] = nums[low];
                        v[2] = nums[high];
                        res.push_back(v);
                        while(low < high && nums[low] == nums[low+1])
                            low++;
                        while(low < high && nums[high] == nums[high-1])
                            high--;
                        low++;
                        high--;
                    } else if (nums[low] + nums[high] < sum){
                        low++;
                    } else {
                        high--;
                    }
                }
            }
        }
        return res;
    }
};