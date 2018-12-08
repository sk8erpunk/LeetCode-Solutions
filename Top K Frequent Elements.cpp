/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int>>> pq;
        unordered_map<int,int> m;
        vector<int> k_freq;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto& p : m){
            int num = p.first;
            int freq = p.second;
            pq.push(make_pair(freq,num));
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            k_freq.push_back(p.second);
        }
        return k_freq;
    }
};