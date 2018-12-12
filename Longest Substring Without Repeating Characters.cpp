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
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> checked(256,-1);
        int longest = 0;
        int start = 0; // substring start;
        int i = 0;
        for(; i < s.size(); i++){
            if(checked[(int)s[i]] == -1){
                checked[(int)s[i]] = i;   
            } else { 
                if(checked[(int)s[i]] >= start){
                    longest = max(longest, i - start);  // found duplicate
                    start = checked[(int)s[i]] + 1;     // update substring begining
                }
                checked[(int)s[i]] = i;
            }
        }
        return max(longest,i-start);
    }
};