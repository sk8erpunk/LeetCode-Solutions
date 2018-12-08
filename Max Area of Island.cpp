/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/
class Solution {
public:
    
    bool isLegal(int i, int j, int m, int n){
        return(i >= 0 && i < m && j >= 0 && j < n);
    }
    
    int DFS(vector<vector<int>>& grid, int i, int j, int m, int n){
        int island_size = 1;
        grid[i][j] = 0;
        
        if(isLegal(i,j+1,m,n) && grid[i][j+1] == 1){
            island_size += DFS(grid, i, j+1, m, n);
        }
        if(isLegal(i-1,j,m,n) && grid[i-1][j] == 1){
            island_size += DFS(grid, i-1, j, m, n);
        }
        if(isLegal(i+1,j,m,n) && grid[i+1][j] == 1){
            island_size += DFS(grid, i+1, j, m, n);
        }
        if(isLegal(i,j-1,m,n) && grid[i][j-1] == 1){
            island_size += DFS(grid, i, j-1, m, n);
        }
        return island_size;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j <grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int size = DFS(grid, i, j, m, n);       
                    max_area = max(size, max_area);
                }
            }
        }
        return max_area;
    }
};