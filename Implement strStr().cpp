/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()){
            return 0;
        }
        if(needle.size() > haystack.size() || haystack.empty()){
            return -1;
        }
        int i=0,index;
        string::iterator ith = haystack.begin(), itn = needle.begin(); 
        while(ith != haystack.end()) {
            if(*ith != *itn){
                ith++;
                i++;
                continue;
            }
            // found a match
            index = i;
            string::iterator next = ith + 1;
            while(*ith == *itn && itn != needle.end()) {
                ith++;
                itn++;
                i++;
            }
            if(itn == needle.end()){
                return index;
            } else {
                itn = needle.begin();
                ith = next;
                i = index + 1;
            }
        }
        return -1;
        
    }
};