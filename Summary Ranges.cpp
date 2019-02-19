/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

Example 2:
Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<string> ranges;
        int count = 1;
        string range = to_string(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1] + 1){
                if(count > 1)
                    range += "->" + to_string(nums[i-1]);
                ranges.push_back(range);
                range = to_string(nums[i]); 
                count = 1;
            } else {
                count++;
            }
        }
        if(count > 1)
            range += "->" + to_string(nums[nums.size()-1]);
        ranges.push_back(range);
        return ranges;
    }
    
};