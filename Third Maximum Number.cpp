/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

class Solution {
public:
    int findMax(unordered_map<int,int>& map){
        int max = (*map.begin()).first;
            for(auto p : map) {
                if(p.first > max){
                    max = p.first;
                }
            }
            return max;
    }
 
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int> counts;
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }
        
        int max = findMax(counts);
        int mapSize = counts.size();
        if(mapSize <= 2){
            return max;
        } else{
            counts.erase(max);
            counts.erase(findMax(counts));
        }
        return findMax(counts);
    }
};