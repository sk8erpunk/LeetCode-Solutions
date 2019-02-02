/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution {
    int MaxLetters = 26;
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) 
            return false;
        vector<int> counter(MaxLetters,0);
        for (int i = 0; i < s.size(); i++)
            counter[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++){
            if(--counter[t[i] - 'a'] < 0)
                return false;
        }    
        return true;  
    }
};