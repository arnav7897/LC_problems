class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dis(n, vector<int>(m, 1e7));

        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            if (effort > dis[x][y])
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {

                    int edgeEffort = abs(h[x][y] - h[nx][ny]);

                    int newEffort = max(effort, edgeEffort);

                    if (newEffort < dis[nx][ny]) {
                        dis[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};