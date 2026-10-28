class Solution {
public:
    int solve(vector<vector<int>>& grid,int row,int col,int m, int n,int xorVal,vector<vector<vector<int>>> &dp){
        xorVal = xorVal^grid[row][col];
        //base case
        if(row == m-1 && col == n-1){
            return xorVal;
        }

        if(dp[row][col][xorVal] != -1){
            return dp[row][col][xorVal]; 
        }

        int right = INT_MAX;
        int down = INT_MAX;

        //going right
        if(col+1 <n){
            right = solve(grid,row,col+1,m,n,xorVal,dp);
        }

        //going down
        if(row+1<m){
            down = solve(grid,row+1,col,m,n,xorVal,dp);
        }
        return dp[row][col][xorVal] = min(right,down);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(); //row
        int n = grid[0].size(); //col
        int xorVal = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1))); //3d dp array

        int ans = solve(grid,0,0,m,n,xorVal,dp);
        return ans;
    }
};