class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,0));
        vector<vector<int>> ans(n , vector<int>(m,0));

        queue<pair<int , pair<int,int>>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0 ;j< m ;j++){
                if(mat[i][j] == 0){
                    q.push({0, {i,j}});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            auto [c,d] = q.front();
            auto [ a, b] = d;
            q.pop();
            ans[a][b] = c;

            int dx[] = {-1 , 1 , 0 , 0};
            int dy[] = {0 , 0 , 1 , -1};

            for(int i = 0;i<4;i++){
                int x = a+dx[i];
                int y = b+dy[i];
                if(x>=0 && y>=0 && x <n && y<m && vis[x][y] == 0){
                    q.push({c+1 , {x,y}});
                    vis[x][y] = true;
                }
            }

        }
        return ans;
    }
};




















