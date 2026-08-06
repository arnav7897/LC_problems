class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , 0));
        queue<pair<int,int>> q;
        int ans = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0 , 0 ,1 ,-1};
        for(int i =0 ;i<n ;i++){
            for(int j = 0; j<m ;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    q.push({i,j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        for(int k =0 ;k<4;k++){
                            int tx = x + dx[k];
                            int ty = y + dy[k];
                            if(tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty] != '1' || vis[tx][ty]){
                                continue;
                            }
                            q.push({tx,ty});
                            vis[tx][ty] = true;
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};