class Solution {
public:
    int parent[26];
    int rank[26];

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else if (rank[a] > rank[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rank[a]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (auto &s : equations) {
            if (s[1] == '=') {
                int a = s[0] - 'a';
                int b = s[3] - 'a';

                unite(a, b);
            }
        }

        for (auto &s : equations) {
            if (s[1] == '!') {
                int a = s[0] - 'a';
                int b = s[3] - 'a';

                if (find(a) == find(b))
                    return false;
            }
        }

        return true;
    }
};