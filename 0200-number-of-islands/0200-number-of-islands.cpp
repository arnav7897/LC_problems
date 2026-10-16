class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , 0));
        int ans = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ;j++){
                if(vis[i][j] || grid[i][j] == '0'){
                    continue;
                }
                ans++;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=1;
                int dx[] = {0,0,1,-1};
                int dy[] = {1,-1,0,0};
                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    
                    for(int k = 0 ;k<4;k++){
                        int nx = x+dx[k];
                        int ny = y+dy[k];

                        if(nx >= 0 && nx < n && ny>=0 && ny<m && grid[nx][ny]=='1' && vis[nx][ny]==false){
                            vis[nx][ny] = true;
                            q.push({nx , ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};