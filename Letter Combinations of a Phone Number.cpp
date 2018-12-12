/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    string digitsChars(char digit){
        vector<string> dic = {"None","None","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        return dic[digit-'0'];
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if(digits.empty()) return combinations;    
        
        string chars = digitsChars(digits[0]);
        
        for(int i = 0; i < chars.size(); i++){
            string s(1,chars[i]);
            combinations.push_back(s);
        }
        for(int i = 1; i < digits.size(); i++){
            string str_i = digitsChars(digits[i]);
            vector<string> v;
            for(int j = 0; j < str_i.size(); j++){
                for(int k = 0; k < combinations.size(); k++){
                    v.push_back(combinations[k]+str_i[j]);
                }
            }
            combinations = v;  
        }
        return combinations;
        
    }
};