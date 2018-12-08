/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    void expand(int start, int end, string s, pair<int,int>* longest){
        while(start >=0 && end < s.size() && s[start] == s[end]){
            start--;
            end++;
        }
        if(longest->second < end-start-1){
            longest->second = end-start-1;
            longest->first = start+1;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.empty() || s.size() < 2) return s;
        pair<int,int> longest = {0,0};
        for(int i = 0; i < s.size(); i++){
            expand(i,i,s,&longest);
            expand(i,i+1,s,&longest);
        }
        return s.substr(longest.first,longest.second);
    }
};