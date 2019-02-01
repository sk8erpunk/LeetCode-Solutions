/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return res;

        res.push_back({1});                             // add top element
        for(int i = 0; i < numRows - 1; i++){
            vector<int> row(1,1);                       // add first 1
            vector<int>& curr = res.back();
            for(int j = 0; j < curr.size() - 1; j++){   // add sums
                row.push_back(curr[j]+curr[j+1]);
            }
            row.push_back(1);                           // add last 1
            res.push_back(row);
        }
        return res;
    }
};