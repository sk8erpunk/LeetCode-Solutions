/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:
Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.

Example 2:
Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int count = 0;
        int maxCount = 0;
        int first = 0, second = -1;
        for(int i = 0; i < s.size(); i++){
            count++;
            if(s[i] == s[first])
                first = i;
            else if(second == -1 || s[i] == s[second])
                second = i;
            else {
                maxCount = max(count-1, maxCount);
                count = abs(first-second)+1;
                first = i;
                second = i-1;
            }
        }
        return max(maxCount,count);
    }
};