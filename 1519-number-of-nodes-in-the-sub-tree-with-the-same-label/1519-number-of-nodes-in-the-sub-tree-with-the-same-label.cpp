class Solution {
public:
    vector<int> ans;

    vector<int> dfs(int node, int parent,
                    vector<vector<int>>& adj, string& labels) {
        vector<int> freq(26, 0);

        for (int child : adj[node]) {
            if (child == parent) continue;

            vector<int> childFreq = dfs(child, node, adj, labels);

            for (int i = 0; i < 26; i++) {
                freq[i] += childFreq[i];
            }
        }

        freq[labels[node] - 'a']++;
        ans[node] = freq[labels[node] - 'a'];

        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        ans.resize(n, 0);
        dfs(0, -1, adj, labels);

        return ans;
    }
};