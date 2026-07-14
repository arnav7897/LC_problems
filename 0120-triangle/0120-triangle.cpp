class Solution {
public:
    int solve(vector<vector<int>>& t,int r,int c,vector<vector<int>>&dp){
        if(r == t.size()){
            return 0;
        }
        if(dp[r][c] != -10001){
            return dp[r][c];
        }
        return dp[r][c] = t[r][c] + min(solve(t,r+1,c,dp) , solve(t,r+1,c+1,dp));
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n , vector<int>(n,-10001));
        return solve(t,0,0,dp);      
    }
};