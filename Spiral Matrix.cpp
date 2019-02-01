/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        int r0 = 0, rm = matrix.size() - 1;
        int c0 = 0, cn = matrix[0].size() - 1;
        while(r0 <= rm && c0 <= cn){
            for(int j = c0; j <= cn; j++)           // right
                res.push_back(matrix[r0][j]);
            r0++;
            for(int i = r0; i <= rm; i++)           // down
                res.push_back(matrix[i][cn]);
            cn--;
            if(r0 <= rm) {
                for(int l = cn; l >= c0; l--)           // left
                    res.push_back(matrix[rm][l]);
            }
            rm--;
            if(c0 <= cn) {
                for(int k = rm; k >= r0; k--)           // up
                    res.push_back(matrix[k][c0]);
            }
            c0++;
        }
        return res;
    }
};