class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& board,char ch){

        for(int i = 0; i<9; i++){
            if(board[row][i] == ch || board[i][col] == ch 
            || board[ (row/3)*3 + i/3][ (col/3)*3 + i%3] == ch){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int n){

        for(int row = 0; row<9; row++){
            for(int col = 0; col<9; col++){
                if(board[row][col] == '.'){

                    for(int i = 1; i<=9; i++){
                        char ch = i + '0';
                        if(isSafe(row,col,board,ch)){
                            board[row][col] = ch;

                            bool isPossible = solve(board,n);

                            if(isPossible){
                                return true;
                            }else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board,9);
    }
};