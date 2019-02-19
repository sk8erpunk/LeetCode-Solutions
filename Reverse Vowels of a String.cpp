/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Input: "hello"
Output: "holle"

Example 2:
Input: "leetcode"
Output: "leotcede"

Note:
The vowels does not include the letter "y".
*/
class Solution {
    string vowels = "aAeEiIoOuU";
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            if(vowels.find(s[i]) != string::npos && vowels.find(s[j]) != string::npos)
                swap(s[i++], s[j--]);
            if(vowels.find(s[i]) == string::npos)
                i++;
            if(vowels.find(s[j]) == string::npos)
                j--;
        }
        return s;
    }
};