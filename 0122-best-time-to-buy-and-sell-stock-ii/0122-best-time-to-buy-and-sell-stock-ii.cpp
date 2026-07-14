class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>>dp(n+1 , vector<int>(2 , 0));
        for(int i = n-1 ;i>=0 ;i--){
                    dp[i][0] = max(dp[i+1][0] , dp[i+1][1] - p[i]);
                    dp[i][1] = max(dp[i+1][1] , dp[i+1][0] + p[i]);
                }
        return dp[0][0];
}
};