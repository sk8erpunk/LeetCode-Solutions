/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    
    bool isCapital(char c){
        return (c >= 65 && c <= 90);
    }
    
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1) return true;
        
        int i;
        // all capitals
        if(isCapital(word[0]) && isCapital(word[1])){
            i = 2;
            while(i < n){
                if(isCapital(word[i]) == false) return false;
                i++;
            }
            return true;
        }
        // first letter capital only or all non capitals
        if(isCapital(word[0]) && !isCapital(word[1]) || !isCapital(word[0]) && !isCapital(word[1])){
            i = 2;
            while(i < n){
                if(isCapital(word[i]) == true) return false;
                i++;
            }
            return true;
        }
    
        return false;
    }
};