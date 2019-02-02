/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:
Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:
Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/

class Solution {
    int N = 9;

    public:
    bool isValidRow(vector<vector<char>>& board, int r){
        int numbers[N] = {0};
        for(int j = 0; j < board[0].size(); j++){
            if(board[r][j] == '.')
                continue;
            if(++numbers[board[r][j]-'0'-1] > 1)
                return false;
        }
        return true;
    }
    
    bool isValidCol(vector<vector<char>>& board, int c){
        int numbers[N] = {0};
        for(int i = 0; i < board.size(); i++){
            if(board[i][c] == '.')
                continue;
            if(++numbers[board[i][c]-'0'-1] > 1)
                return false;
        }
        return true;
    }
    
    bool isValidSquare(vector<vector<char>>& board, int row, int col){
        int numbers[N] = {0};
        int n = col + N/3, m = row + N/3;
        for(int i = row ; i < m; i++){
            for(int j = col; j < n; j++){
                if(board[i][j] == '.')
                    continue;
                if(++numbers[board[i][j]-'0'-1] > 1)
                    return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            if(!isValidRow(board,i))
                return false;
        }
        for(int j = 0; j < board[0].size(); j++){
            if(!isValidCol(board,j))
                return false;
        }
        for(int i = 0; i < N; i+=3){
            for(int j = 0; j < N; j+=3){
                if(!isValidSquare(board,i,j))
                    return false;
            }
        } 
        return true;
    }
};