class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        queue<int> q; 
        
        int n = graph.size();
        
        vector<vector<int>> adj(n);

        vector<int> out(n , 0);
        for(int i = 0;i< n;i++){
            for(int j = 0;j<graph[i].size() ;j++){
                adj[graph[i][j]].push_back(i);
                out[i]++;
            }
        }
        
        for(int i = 0;i<n;i++){
            if(out[i] ==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v = q.front();
            ans.push_back(v);
            q.pop();

            for(auto &it : adj[v]){
                out[it]--;
                if(out[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};