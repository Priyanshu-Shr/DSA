class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& grid,
    vector<vector<bool>> &visited,bool &flag,int k,int n,int m){

        visited[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});

        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        long long sum = 0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int node = grid[front.first][front.second];
            for(int k = 0; k<4; k++){
                int nrow = front.first + dx[k];
                int ncol = front.second + dy[k];

                if(nrow <0 || nrow>=n || ncol<0 || ncol>=m){
                    continue;
                }
                if(!visited[nrow][ncol] && grid[nrow][ncol] !=0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = true;
                }
            }
            sum += node;
        }
        if(sum%k == 0){
            flag = true;
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] != 0){
                    bool flag = false;
                    bfs(i,j,grid,visited,flag,k,n,m);
                    if(flag)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};