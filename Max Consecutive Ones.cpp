/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0;
        int max = 0;
        while(i < nums.size()){
            if(nums[i] == 0){
                if(j > max){
                    max = j;
                }
                j = 0;
            } else {
                j++;
            }
            i++;
        }
       
        return j > max? j : max;
    }
};