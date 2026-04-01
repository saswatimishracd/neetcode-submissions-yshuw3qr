class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9),cols(9),box(9);
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                int boxNo = (row/3)*3+col/3;
                int num = board[row][col];
                if(board[row][col]=='.') continue;
                if(rows[row].count(num) || cols[col].count(num) || box[boxNo].count(num)) return false;
                rows[row].insert(num);
                cols[col].insert(num);
                box[boxNo].insert(num);
            }
        }
                return true;
    }
};
