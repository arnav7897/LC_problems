class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, pair<int, int>>> q;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }

        int maxi = 0;

        while (!q.empty()) {

            auto [time, pos] = q.front();
            auto [x, y] = pos;
            q.pop();

            // Up
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                maxi = max(maxi, time + 1);
                q.push({time + 1, {x - 1, y}});
            }

            // Down
            if (x + 1 < n && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                maxi = max(maxi, time + 1);
                q.push({time + 1, {x + 1, y}});
            }

            // Right
            if (y + 1 < m && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                maxi = max(maxi, time + 1);
                q.push({time + 1, {x, y + 1}});
            }

            // Left
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                maxi = max(maxi, time + 1);
                q.push({time + 1, {x, y - 1}});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return maxi;
    }
};
