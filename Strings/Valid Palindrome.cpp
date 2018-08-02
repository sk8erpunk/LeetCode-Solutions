/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false

*/
class Solution {
public:
    bool isLetter(char c){
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')); 
    }
    bool sameLetter(char c1, char c2){
        return ((isLetter(c1) && isLetter(c2)) && (abs(c1 - c2) == 32) || c1 - c2 == 0);
    }
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int first = 0, last = s.size() - 1;
        while(first <= last){
            if(isalnum(s[first]) == false){
                first++;
                continue;
            }
            if(isalnum(s[last]) == false){
                last--;
                continue;
            }
            if(sameLetter(s[first],s[last]) == false){            
                return false;
            }
            first++;
            last--;
        }
        return true;
    }
};