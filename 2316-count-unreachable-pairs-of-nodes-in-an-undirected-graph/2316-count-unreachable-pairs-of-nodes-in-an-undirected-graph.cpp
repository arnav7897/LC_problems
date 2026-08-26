class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int n){
        if(parent[n] == n ){
            return n;
        }
        return parent[n] = find(parent[n]);
    }

    void unite(int n, int m){
        int p_n = find(n);
        int p_m = find(m);

        if(rank[p_n] > rank[p_m]){
            parent[p_m] = p_n;
        }else if(rank[p_n] < rank[p_m]){
            parent[p_n] = p_m;
        }else{
            parent[p_n] = p_m;
            rank[p_n]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }        

        for(auto&it : edges){
            unite(it[0] , it[1]);
        }

        // find the pairs
        long long ans = 0;

        unordered_map<int,int> f;
        
        for(int i =0 ;i<n;i++){
            f[find(i)]++;
        }
        long long prev = 0;
        for(auto &[a,b]:f){
            ans += 1ll*prev*b;
            prev += b;
        }
        return ans;
    }
};