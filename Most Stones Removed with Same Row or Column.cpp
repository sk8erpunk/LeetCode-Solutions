/*
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.
Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
What is the largest possible number of moves we can make? 

Example 1:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5

Example 2:
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3

Example 3:
Input: stones = [[0,0]]
Output: 0

Note:
1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
*/
class Solution {
    public:
    void dfs(vector<vector<int>>& stones, int r, int c, unordered_map<int, unordered_set<int>>& visited){
        if(visited.count(r) == 0)
            visited[r] = unordered_set<int>();
        visited[r].insert(c);
        for(int i = 0; i < stones.size(); i++){
            int row = stones[i][0];
            int col = stones[i][1];
            if(visited.count(row) == 0 || visited[row].count(col) == 0){
                if(row == r || col == c){               // has same col or row
                    dfs(stones, row, col, visited);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int numOfIslands = 0;
        unordered_map<int, unordered_set<int>> visited;
        for(int i = 0; i < stones.size(); i++){
            int row = stones[i][0];
            int col = stones[i][1];
            if(visited.count(row) == 0 || visited[row].count(col) == 0){        // if cell not visited
                dfs(stones, row, col, visited);
                numOfIslands++;
            }
        }
        return stones.size() - numOfIslands;
    }
};