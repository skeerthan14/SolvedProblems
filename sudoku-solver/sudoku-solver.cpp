class Solution {
public:
    bool isSafe(int row, int col, char c, vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            if(board[row][i]==c || board[i][col]==c || board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c) return false;
        }
        return true;
    }
    
    bool generate(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                    for(char c = '1';c<='9';c++) {
                        if(isSafe(i, j, c, board)) {
                            board[i][j] = c;
                            if(generate(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        generate(board);
    }
};