class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int src, int des) {
        vector<vector<int>> adj(n);
        for(auto& it: e){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }      

        queue<int> q;
        q.push(src);
        vector<int> vis(n,0);
        vis[src] = 1;
        while(!q.empty()){
            int top = q.front();
            if(top == des){
                return true;
            }
            q.pop();
            for(auto &it : adj[top]){
                if(vis[it] == 0){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return false;
    }
};