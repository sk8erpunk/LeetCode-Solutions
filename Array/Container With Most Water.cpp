/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int l = 0, h = height.size() - 1;
        while(l < h){
            int curr_area = min(height[l],height[h])*(h-l);
            if(curr_area > max){
                max = curr_area;
            }
            if(height[l]<height[h]){
                l++;
            } else {
                h--;
            }
        }
        return max;
    }
};