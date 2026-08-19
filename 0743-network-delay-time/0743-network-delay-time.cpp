class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, k});

        while(!pq.empty()) {

            auto [dist, node] = pq.top();
            pq.pop();

            if(dist > dis[node])
                continue;

            for(auto &[nextNode, weight] : adj[node]) {

                if(dis[nextNode] > dist + weight) {

                    dis[nextNode] = dist + weight;

                    pq.push({dis[nextNode], nextNode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dis[i] == INT_MAX)
                return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};