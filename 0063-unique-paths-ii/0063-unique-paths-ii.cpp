class Solution {
public:
    int solve(vector<vector<int>>& o , int m , int n,vector<vector<int>> &dp){
        if(n<0 || m<0){
            return 0;
        }
        if(o[m][n] == 1){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(dp[m][n] !=-1){
            return dp[m][n];
        }
        int ans = 0;
        ans += solve(o , m-1 , n,dp);
        ans += solve(o , m , n-1,dp);
        return dp[m][n] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m = o.size();
        int n = o[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(o,m-1,n-1,dp);
    }
};