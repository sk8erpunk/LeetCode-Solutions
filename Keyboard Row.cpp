/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard.

Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
 

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

class Solution {
    // keyboard
    string up = "QqWwEeRrTtYyUuIiOoPp";
    string mid = "AaSsDdFfGgHhJjKkLl";
    string down = "ZzXxCcVvBbNnMm";
    unordered_set<char> upTable, midTable, downTable;

    public:
    // O(1) since letters are of a const size
    void fillTable(unordered_set<char>& table, string& letters){
        for(int i = 0; i < letters.size(); i++)
            table.insert(letters[i]);
    }
    
    // O(1) since it's a hashset
    unordered_set<char>& findTable(char c){
        if(upTable.count(c))
            return upTable;
        else if(downTable.count(c))
            return downTable;
        else 
            return midTable;
    }
    
    
    vector<string> findWords(vector<string>& words) {
        // fill sets
        fillTable(upTable,up);
        fillTable(midTable,mid);
        fillTable(downTable,down);
        
        vector<string> res;
        for(int i = 0; i < words.size(); i++){
            bool addWord = true;
            string& curr = words[i];
            unordered_set<char>& table = findTable(curr[0]);
            for(int j = 0; j < curr.size(); j++){
                if(table.count(curr[j]) == 0){
                    addWord = false;
                    break;
                }
            }
            if(addWord)
                res.push_back(curr);
        }
        return res;
    }
};