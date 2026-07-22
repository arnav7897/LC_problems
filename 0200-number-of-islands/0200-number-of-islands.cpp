class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        queue<pair<int, int>> q;
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    // traversal
                    c++;
                    q.push({i, j});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        auto [a, b] = q.front();
                        vis[a][b] = true;
                        q.pop();

                        // Down
                        if (a + 1 < n && !vis[a + 1][b] &&
                            grid[a + 1][b] == '1') {
                            q.push({a + 1, b});
                            vis[a + 1][b] = true;
                        }

                        // Up
                        if (a - 1 >= 0 && !vis[a - 1][b] &&
                            grid[a - 1][b] == '1') {
                            q.push({a - 1, b});
                            vis[a - 1][b] = true;
                        }

                        // Right
                        if (b + 1 < m && !vis[a][b + 1] &&
                            grid[a][b + 1] == '1') {
                            q.push({a, b + 1});
                            vis[a][b + 1] = true;
                        }

                        // Left
                        if (b - 1 >= 0 && !vis[a][b - 1] &&
                            grid[a][b - 1] == '1') {
                            q.push({a, b - 1});
                            vis[a][b - 1] = true;
                        }
                    }
                }
            }
        }
        return c;
    }
};