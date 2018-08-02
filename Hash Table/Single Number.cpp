/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        for( auto const& p : map){
            if(p.second == 1){
                return p.first;
            }
        }
        return -1;
    }
};