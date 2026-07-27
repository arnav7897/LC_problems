class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < f.size(); i++) {
            adj[f[i][0]].push_back({f[i][1], f[i][2]});
        }

        vector<int> dis(n, 1e9);
        dis[src] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto [stop, d] = q.top();
            auto [v, price] = d;

            q.pop();

            if (stop == k+1) {
                continue;
            }

            for (auto it : adj[v]) {
                if (dis[it.first] > price + it.second) {
                    q.push({stop +1, {it.first, price + it.second}});
                    dis[it.first] = price + it.second;
                }
            }
        }
        if (dis[dst] == 1e9) {
            return -1;
        }
        return dis[dst];
    }
};