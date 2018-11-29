/*
Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"
Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
*/

class Solution {
public:
    string reverseString(string s) {
        for(int i = 0, j = s.size()-1; i < j; i++,j--){
            swap(s[i],s[j]);
        }   
        return s;
    }
};