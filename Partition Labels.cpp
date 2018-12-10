/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:

The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
*/

class Solution {
    int LETTERS_MAX = 26;
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        if(S.empty()) return res;
        int* start = new int[LETTERS_MAX];
        int* end = new int[LETTERS_MAX];

        // initialize intervals
        for(int i = 0; i < LETTERS_MAX; i++){
            start[i] = end[i] = -1;
        }
        
        // find intervals
        for(int i = 0; i < S.size(); i++){
            if(start[S[i]-'a'] == -1){
                start[S[i]-'a'] = i;
                end[S[i]-'a'] = i;
            }
            else {
                end[S[i]-'a'] = i;
            }
        }
        int pStart = start[S[0]-'a'];
        int pEnd = end[S[0]-'a'];
        for(int i = 1; i < S.size(); i++){
            if(end[S[i]-'a'] < pEnd){
                continue;
            }
            else if(start[S[i]-'a'] < pEnd){
                pEnd = end[S[i]-'a'];
            }
            else {
                res.push_back(pEnd-pStart+1);
                pStart = start[S[i]-'a'];
                pEnd = end[S[i]-'a'];
            }
        }
        res.push_back(pEnd-pStart+1);
        return res;
    }
};