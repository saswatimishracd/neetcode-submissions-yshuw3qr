class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9),col(9),boxes(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int boxIdx = (i/3)*3+j/3;
                int num=board[i][j];
                if(board[i][j]=='.') continue;
                if(row[i].count(num)||col[j].count(num)||boxes[boxIdx].count(num)){
                    return false;
                }
                row[i].insert(num);
                col[j].insert(num);
                boxes[boxIdx].insert(num);
            }
        }
            return true;
    }
};
