/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2

Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = nums.size()*(nums.size()+1)/2;    // sum all numbers from 0 to n
        for(int i = 0 ; i < size; i++){
            sum -= nums[i];
        }
        return sum;
    }
};