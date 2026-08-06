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
        vector<vector<int>> dp(n , vector<int>(2,-1));
        return solve(p , 0 , true ,dp);   
    }
};