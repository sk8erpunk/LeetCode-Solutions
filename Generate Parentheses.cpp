/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    void helper(vector<string>& res, int left, int right, vector<char>& p, int idx){
        if(left < 0 || right < left)
            return;

        if(left == 0 && right == 0){
            string s(p.begin(),p.end());
            res.push_back(s);
        } else {
            p[idx] = '(';
            helper(res, left-1, right, p, idx+1);

            p[idx] = ')';
            helper(res, left, right-1, p, idx+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<char> p(n*2,'0');
        helper(res,n,n,p,0);
        return res;
    }
};