class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                else if(rows[i].find(board[i][j]) != rows[i].end() || cols[j].find(board[i][j]) != cols[j].end() || boxes[(i/3)*3+(j/3)].find(board[i][j]) != boxes[(i/3)*3+(j/3)].end() ){
                    return false;
                }
                    
                else {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[(i/3)*3+(j/3)].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
