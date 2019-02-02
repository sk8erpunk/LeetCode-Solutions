/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
    int MaxLetters = 256;
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(MaxLetters,-1);
        int maxStr = 0;
        int start = -1;                               // str start;
        for(int i =0 ; i < s.size(); i++){
            start = max(start, seen[s[i]]);
            seen[s[i]] = i;                         // save in seen
            maxStr = max(maxStr, i - start);        // update max
        }
        return maxStr;
    }
};