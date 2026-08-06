class Solution {
public:
    int solve(vector<int>& p , int i , bool s ,  vector<vector<int>> &dp){
        int n = p.size();
        if(i >= n){
            return 0;
        }
        int se = s ? 1:0;
        if(dp[i][se]!=-1){
            return dp[i][se];
        }
        if(s){
            return dp[i][se] = max(solve(p , i+1 , false , dp)-p[i] , solve(p , i+1 , s , dp));
        }else{
            return dp[i][se] = max(p[i] , solve(p , i+1 , s, dp));
        }
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+1 , vector<int>(2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i = n-1; i>=0 ;i--){
            for(int j = 1; j>=0;j--){
                if(j == 1){
                    dp[i][j] = max(dp[i+1][j] , p[i]);
                }else{
                    dp[i][j] = max(dp[i+1][j+1] - p[i], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];   
    }
};