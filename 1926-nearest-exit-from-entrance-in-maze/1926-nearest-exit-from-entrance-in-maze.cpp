class Solution {
public:
    int nearestExit(vector<vector<char>>& mat, vector<int>& e) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<pair<int, int>, int>> q;

        q.push({{e[0], e[1]}, 0});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[e[0]][e[1]] = 1;

        while (!q.empty()) {
            auto [a, d] = q.front();
            auto [i, j] = a;
            q.pop();

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && y >= 0 && x < n && y < m &&
                    mat[x][y] == '.' && vis[x][y] == 0) {

                    if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                        return d + 1;
                    }

                    vis[x][y] = 1;
                    q.push({{x, y}, d + 1});
                }
            }
        }

        return -1;
    }
};