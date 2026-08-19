class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m, false));
        queue<pair<int,int>> q;
        int ans = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0 , 0, 1 , -1};
        for(int i =0 ;i<n;i++){
            for(int j =0 ; j<m ;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    q.push({i,j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        auto [a,b] = q.front();
                        q.pop();
                        for(int i =0 ;i<4;i++){
                            int x = a + dx[i];
                            int y = b + dy[i];
                            
                            if(x >= 0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y] == '1'){
                                q.push({x,y});
                                vis[x][y] = true;
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};