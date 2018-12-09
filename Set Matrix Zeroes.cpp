/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool colFlag = false;
        bool rowFlag = false;
        
        // check first row if it has zero
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                rowFlag = true;
                break;
            } 
        }
        
        // check first col if it has zero
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                colFlag = true;
                break;
            } 
        }
        
        // checking all cols and rows 
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                } 
            }
        }
        
        // zeroing cols and rows 
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                } 
            }
        }
        
        // zeroing first row
        if(rowFlag){
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
        }
        
        // zeroing first col 
        if(colFlag){
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;  
        }
    }
};