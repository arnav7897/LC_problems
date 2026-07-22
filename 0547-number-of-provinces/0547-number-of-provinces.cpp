class Solution {
public:
    void traverse(vector<vector<int>>& isConnected , int s , vector<bool>&vis){
        queue<int> q;
        q.push(s);
        vis[s] = true;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(int i = 0;i<isConnected[f].size() ; i++){
                if(isConnected[f][i] == 1 && !vis[i]){ //edge
                    vis[i] = true;
                    q.push(i);
                }
            }   
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int c =0;
        int n = isConnected.size();
        vector<bool> vis(n , 0);
        for(int i = 0;i<n ;i++){
            if(!vis[i]){
                c++;
                traverse(isConnected , i , vis);
            }
        }
        return c;
    }
};