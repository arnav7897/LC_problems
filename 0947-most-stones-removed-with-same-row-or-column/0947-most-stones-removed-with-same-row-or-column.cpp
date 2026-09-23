class Solution {
public:
    int find(int i , vector<int>&p){
        if(p[i] == i){
            return i;
        }
        return p[i] = find(p[i] , p);
    }
    void uni(vector<int>& rank, vector<int>& p, int a, int b) {
        int p_a = find(a , p);
        int p_b = find(b , p);

        if(rank[p_a] > rank[p_b]){
            p[p_b] = p_a;
        }else if(rank[p_a] < rank[p_b]){
            p[p_a] = p_b;
        }else{
            p[p_b] = p_a ;
            rank[p_a]++; 
        }
    }
    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        vector<int> rank(n, 0);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if(s[i][0] == s[j][0] || s[i][1] == s[j][1]){
                    uni(rank , p , i , j);
                }
            }
        }
        unordered_map<int, int> mp;
        for(int i = 0;i<n;i++){
            mp[find(p[i],p)]++;
        }
        int ans = 0;
        for(auto &[a,b] : mp){
            if(b>1){
                ans += b-1;
            }
        }
        return ans;
    }
};