class Solution {
public:
    int help(vector<vector<int>>&dp ,vector<int>& p ,int s, int e ){
        if(e<s){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int t1 = p[s] + min(help(dp , p , s+2 , e) , help(dp,p,s+1,e-1));
        int t2 = p[e] + min(help(dp , p , s+1 , e-1) , help(dp, p , s, e-2));

        return dp[s][e] = max(t1 , t2);
    }
    bool stoneGame(vector<int>& p) {
        int sum = 0;
        int n = p.size();
        for(int i =0 ;i<n;i++){
            sum += p[i];
        }
        vector<vector<int>> dp(n , vector<int>(n,-1));
        int a = help(dp,p,0,n-1);
        return a > sum/2;
    }
};