/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
Could you do this in O(n) runtime?

Example:
Input: [3, 10, 5, 25, 2, 8]
Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, max = 0;
        for(int i = 31; i >= 0; i--){
            mask = mask | (1 << i);
            unordered_set<int> prefixSet;
            // push all prefixes of each number
            for(auto num : nums)    
                prefixSet.insert(num & mask);

            // potential max 
            int tmp = max | (1 << i);
            
            // if there exist a = tmp ^ b then tmp is max (equivalent to a^b=tmp)
            for(auto& prefix : prefixSet){
                if(prefixSet.count(tmp ^ prefix)){
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};