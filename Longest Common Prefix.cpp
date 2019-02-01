/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size() == 0) return prefix;
        
        int shortStrLen = strs[0].size();
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() < shortStrLen)
                shortStrLen = strs[i].size();
        }
        
        int i = 0;
        while(i < shortStrLen){
            char letter = strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != letter) // found diff letter, stop!
                    return prefix;
            }
            prefix += letter;
            i++;
        }
        return prefix;
    }
};