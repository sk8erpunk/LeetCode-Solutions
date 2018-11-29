/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2) {
            return false;
        } 
        int n = nums.size();
        int i = 0;
        while(i <= max(n-k-1,0)){
            int start = i;
            while(start < min(i+k,n-1)){
                if(nums[start] == nums[min(i+k,n-1)]) return true;
                start++;
            }
            i++;
        }
        return false;
    }
};