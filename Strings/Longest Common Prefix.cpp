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
        vector<string>::iterator it;
        if(!strs.size()){
            return prefix;
        }
        int min_len = strs[0].size();
        
        for(it = strs.begin(); it < strs.end(); it++){
            if((*it).size() < min_len){
                min_len = (*it).size();
            }
        }
        int i = 0;
        while(i < min_len){
            char curr = strs[0][i];
            for(it = strs.begin(); it < strs.end(); it++){
                if((*it)[i] != curr){
                    return prefix;
                }
            }
            prefix += curr;
            i++;
        }
        return prefix;
    }
};