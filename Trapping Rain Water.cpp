/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxLeft = 0;
        int maxRight = 0;
        int res = 0;
        while(l < r){
            if(height[l] < height[r]){
                height[l] >= maxLeft ? maxLeft = height[l] : res += maxLeft - height[l];
                l++;
            } else {
                height[r] >= maxRight ? maxRight = height[r] : res += maxRight - height[r];
                r--;
            }
        }
        return res;
    }
};