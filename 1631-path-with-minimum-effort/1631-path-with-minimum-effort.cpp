class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;

        q.push({0, {0, 0}});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [a, d] = q.top();
            q.pop();

            auto [b, c] = d;

            if (a > dis[b][c])
                continue;

            if (b == n - 1 && c == m - 1)
                return a;

            for (int i = 0; i < 4; i++) {
                int x = b + dx[i];
                int y = c + dy[i];

                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;

                int diff = abs(h[x][y] - h[b][c]);
                int effort = max(a, diff);

                if (dis[x][y] > effort) {
                    dis[x][y] = effort;
                    q.push({effort, {x, y}});
                }
            }
        }

        return 0;
    }
};
