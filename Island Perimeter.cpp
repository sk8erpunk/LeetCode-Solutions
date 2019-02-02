/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1.
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

*/
class Solution {
public:
    
    int checkNeighbor(vector<vector<int>>& grid, int i, int j){
        return (i < 0 || j < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j]) ? 0 : 1;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0)
                    continue;
                if(i == 0)
                    perimeter++;
                if(i == grid.size()-1)
                    perimeter++;
                if(j == 0)
                    perimeter++;
                if(j == grid[0].size()-1)
                    perimeter++;
                perimeter += checkNeighbor(grid,i+1,j);
                perimeter += checkNeighbor(grid,i-1,j);
                perimeter += checkNeighbor(grid,i,j+1);
                perimeter += checkNeighbor(grid,i,j-1);
            }
        }
        return perimeter;
    }
};