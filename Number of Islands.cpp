/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    
    bool isLegalBorder(int i, int j, int m, int n){
        return ((i >=0 && i < m) && (j >=0 && j < n));
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        int n = grid[0].size();
        int m = grid.size();
        if(isLegalBorder(i, j+1, m, n) && grid[i][j+1] == '1'){
            DFS(grid, i, j+1);
        }
        if(isLegalBorder(i+1, j, m, n) && grid[i+1][j] == '1'){
            DFS(grid, i+1, j);
        }
        if(isLegalBorder(i, j-1, m, n) && grid[i][j-1] == '1'){
            DFS(grid, i, j-1);
        }
        if(isLegalBorder(i-1, j, m, n) && grid[i-1][j] == '1'){
            DFS(grid, i-1, j);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {  
        int islands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    islands++;
                    DFS(grid, i , j);
                }
            }
        }
        return islands;
    }
};