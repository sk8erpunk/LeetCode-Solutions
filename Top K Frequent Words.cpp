/*
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.

Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

class Solution {
public:
    typedef pair<int,string> Element;
    
    static bool compPairs(Element p1, Element p2){
        if (p1.first > p2.first)
            return true;
        else if(p1.first < p2.first)
            return false;
        else 
            return p1.second < p2.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<Element, vector<Element>, bool (*)(Element, Element)> pq(compPairs);
        unordered_map<string,int> map;
        
        for(int i = 0; i < words.size(); i++)
            map[words[i]]++;
        
        for(auto& p : map){
            pq.push(make_pair(p.second,p.first));
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> res;
        while(!pq.empty()){ 
            res.insert(res.begin(),pq.top().second);
            pq.pop();
        }
        return res;
    }
};