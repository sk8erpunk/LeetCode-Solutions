/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.empty() || !wordSet.count(endWord)) return 0;
        
        list<string> queue;
        queue.push_back(beginWord);
        int dist = 1;
        
        while(!queue.empty()){
            int n = queue.size();
            for(int i = 0; i < n; i++){
                string curr = queue.front();
                queue.pop_front();
                if(endWord == curr)
                    return dist;
                // add all transformed words O(curr.size())
                for(char& c : curr){
                    int temp = c;
                    for(int j = 0; j < 26; j++){
                        c = 'a' + j;
                        if(wordSet.count(curr)){
                            queue.push_back(curr); 
                            wordSet.erase(curr); // visited
                        }
                    }
                    c = temp;
                }
            }
            dist++;   // finished level
        }
        return 0;
    }
};