class Solution {
public:

    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>&visited,bool & flag,int n,int m){
        visited[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});

        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            for(int k = 0; k<4; k++){
                int nrow = p.first + dx[k];
                int ncol = p.second + dy[k];

                if( (nrow <0 || nrow >=n) || (ncol <0 || ncol>=m) ){
                    flag = true;
                }
                else if(!visited[nrow][ncol] && grid[nrow][ncol] == 0){
                    visited[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
       int n = grid.size(); //rows
       int m = grid[0].size(); //columns
       vector<vector<bool>>  visited(n,vector<bool>(m,false));
        int cnt = 0;

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                bool flag = false; //to check if the island is near boundary of grid or not
                if(!visited[i][j] && grid[i][j] == 0){
                    bfs(i,j,grid,visited,flag,n,m);
                    if(!flag){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};