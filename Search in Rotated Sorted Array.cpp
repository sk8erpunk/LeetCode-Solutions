/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class Solution {
public:
    
    int findIndexOfFirst(vector<int>& nums, int start, int end){
        while(start < end) {
            if(nums[start] < nums[end])
                return start;
            int mid = (start + end)/2;
            if(nums[mid] >= nums[start])
                start = mid + 1;
            else 
                end = mid; 
        }
        return start;
    }
        
    int binarySearch(vector<int>& nums, int start, int end, int target){
        if(start > end)
            return -1;
        int mid = (start+end)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            return binarySearch(nums, start, mid-1, target);
        else 
            return binarySearch(nums, mid+1, end, target);
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return target == nums[0] ? 0 : -1;
        int first = findIndexOfFirst(nums, 0, nums.size()-1);
        if(nums[first] == target)
            return first;
        if(first == 0)
            return binarySearch(nums, 0, nums.size()-1, target);
        if(nums[0] > target)
            return binarySearch(nums, first, nums.size()-1, target);
        else 
            return binarySearch(nums, 0, first, target);
    }
};