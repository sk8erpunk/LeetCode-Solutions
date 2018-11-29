/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

 

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15

*/

class Solution {
public:
    bool checkIfGrid(vector<vector<int>>& grid, int n , int m){
        int sum_row = 0, sum_col = 0, sum_diagnosal1 = 0, sum_diagnosal2 = 0;
        int tot_sum = 0;
        int pass = 0;
        int* count = new int[10];
        for(int i = 0; i < 10; i++){
            count[i] = 0;
        } 
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++){    
                if(grid[n+i][m+j] > 9 || grid[n+i][m+j] <= 0){
                    return false;
                }
                if(++count[grid[n+i][m+j]] > 1){
                    cout << "oops";
                    return false;
                }
                sum_row += grid[n+i][m+j];
                sum_col += grid[n+j][m+i];
                if(i+j == 2){
                    sum_diagnosal2 += grid[n+i][m+j];
                }
                if(i == j){
                    sum_diagnosal1 += grid[n+i][m+j];
                }
            }
            if(sum_row != sum_col){ 
                return false;
            } 
            if(pass){
               if(tot_sum != sum_row){
                   return false;
               }     
            }
            if(pass == 0){
                tot_sum = sum_row;
                pass = 1;    
            }
            sum_row = 0;
            sum_col = 0; 
        }
        if(((sum_diagnosal1 != sum_diagnosal2) || (tot_sum != sum_diagnosal1))){
            return false;
        }
        return true;
    }
            
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 || grid[0].size() < 3){
            return 0;
        }
        int count_grids = 0;
        for (int n = 0; n < grid.size() - 2; n++){  //rows
            for (int m = 0; m < grid[0].size() - 2; m++) { //columns
                if(checkIfGrid(grid, n , m)){
                    count_grids++;
                } 
            }
        }
        return count_grids;
    }
};