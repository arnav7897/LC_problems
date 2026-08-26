class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int n) {
        if(n == parent[n]) {
            return n;
        }

        return parent[n] = find(parent[n]);
    }

    void merge(int n, int m) {
        int n_p = find(n);
        int m_p = find(m);

        if(n_p == m_p) {
            return;
        }

        if(rank[n_p] > rank[m_p]) {
            parent[m_p] = n_p;
        }
        else if(rank[m_p] > rank[n_p]) {
            parent[n_p] = m_p;
        }
        else {
            parent[m_p] = n_p;
            rank[n_p]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& c) {
        parent.resize(n);
        rank.resize(n, 0);
        if(c.size() < n-1){
            return -1;
        }
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(int i = 0; i < c.size(); i++) {
            merge(c[i][0], c[i][1]);
        }

        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            st.insert(find(i));
        }

        return st.size() - 1;
    }
};