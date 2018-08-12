/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?

*/

class Solution {
    
public:
    
    int pushString(string& w, char* arr){
        string::iterator it = w.begin();
        int len = 0; 
        while(it != w.end()){
            if(*it != '#'){
                arr[len++] = *it;
            } else {
                if(len > 0){
                    len--;
                }  
            }
            it++;
        }
        arr[len] = '\0';
        return len;
    }
    
    bool backspaceCompare(string S, string T) {
        char* s1 = new char[200];
        char* s2 = new char[200];
        
        int len1 = pushString(S, s1);
        int len2 = pushString(T, s2);
        if(len1 != len2) return false;
        int i = 0;
        while(i < len1){
            if(s1[i] != s2[i]) return false;
            i++;
        } 
        return true;
    }
};