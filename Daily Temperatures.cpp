/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n,0);
        unordered_map<int,int> next; // index of next bigger
        next[T[n-1]] = n;  // index of last is marked n
        for(int i = n-2; i >= 0; i--){
            if(T[i] < T[i+1]){
                res[i] = 1;
                next[T[i]] = i+1;
            } else {
                int biggerIdx = next[T[i+1]];
                while(biggerIdx < n && T[biggerIdx] <= T[i])  // look for next bigger 
                    biggerIdx = next[T[biggerIdx]];
                res[i] = biggerIdx < n ? biggerIdx - i : 0;
                next[T[i]] = biggerIdx;
            }
        }
        return res;
    }
};