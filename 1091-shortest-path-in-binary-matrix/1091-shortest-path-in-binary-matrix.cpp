class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, 1e9));

        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0] ==1 || grid[n-1][n-1]==1){
            return -1;
        }
        q.push({1, {0, 0}});

        int dirx[] = {1, 0, -1, 0, 1, 1, -1, -1};
        int diry[] = {0, 1, 0, -1, 1, -1, 1, -1};

        while (!q.empty()) {
            auto [a, d] = q.front();
            auto [b, c] = d;
            q.pop();

            if (b == n - 1 && c == n - 1) {
                return a;
            }
            int x ,y;
            for(int i = 0;i<8;i++){
                x = b + dirx[i];
                y = c + diry[i];
                if(x < 0 || y<0 || x>=n || y>=n || grid[x][y] == 1){
                    continue;
                }
                if(dis[x][y] > a+1){
                    q.push({a+1,{x,y}});
                    dis[x][y] = a+1;
                }
            }
        }
        return -1;
    }
};