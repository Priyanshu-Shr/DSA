class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> leftUp;
    unordered_map<int,bool> leftDown;

    bool isSafe(int row,int col,int n){
        if(rowCheck[row] == false && leftDown[row + col] == false &&
        leftUp[n-1 + col-row] == false){
            return true;
        }
        return false;
    }

    void storeAns(vector<vector<string>> &ans,vector<vector<string>>& board,int n){
        vector<string> temp;
        for(int row = 0; row<n; row++){
            string s = "";
            for(int col = 0; col<n; col++){
                s += board[row][col];
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    void solve(int col,vector<vector<string>> &ans,vector<vector<string>>& board,int n){

        //base case
        if(col == n){
            storeAns(ans,board,n);
            return;
        }

        //for all rows
        for(int row = 0; row<n; row++){
            if(isSafe(row,col,n)){
                //placing the queen
                board[row][col] = "Q";
                rowCheck[row] = true;
                leftUp[n-1 + col-row] = true;
                leftDown[row+col] = true;
                //recursive call
                solve(col+1,ans,board,n);

                //backtracking
                board[row][col] = ".";
                rowCheck[row] = false;
                leftUp[n-1 + col-row] = false;
                leftDown[row+col] = false;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n,vector<string>(n,"."));
        int col = 0;
        vector<vector<string>> ans;
        solve(col,ans,board,n);
        return ans;
    }
};