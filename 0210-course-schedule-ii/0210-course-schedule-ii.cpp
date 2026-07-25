class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> in(n, 0);

        for (auto& e : prerequisites) {
            adj[e[1]].push_back(e[0]); // prerequisite -> course
            in[e[0]]++;                // indegree of course
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (in[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            ans.push_back(v);

            for (int it : adj[v]) {
                in[it]--;
                if (in[it] == 0)
                    q.push(it);
            }
        }

        if (ans.size() == n)
            return ans;

        return {};
    }
};
