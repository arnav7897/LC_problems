class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>> dp(n+1 , vector<int>(2,0));
        for(int i = n-1; i>=0 ;i--){
            for(int j = 1; j>=0 ;j--){
                if(j==1){
                    dp[i][j] = max(dp[i+1][1] , dp[i+1][0] + p[i] - fee);
                }else{
                    dp[i][j] = max(dp[i+1][0] , dp[i+1][1] - p[i]); 
                }
            }
        }
        return dp[0][0];
    }
};