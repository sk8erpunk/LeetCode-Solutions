/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
class Solution {
public:
    int binarySearchVector(vector<int>& nums, int target, int start, int end){
        if(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target ){
                if(mid+1 > end){
                    return mid+1;
                } else {
                    return binarySearchVector(nums,target,mid+1,end);;
                }
                
            } else {
                if(mid-1 < start){
                    return start;
                } else {
                    return binarySearchVector(nums,target,start,mid-1);
                }
            }
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return 0;
        }
        return binarySearchVector(nums,target,0,nums.size()-1);
    }
};