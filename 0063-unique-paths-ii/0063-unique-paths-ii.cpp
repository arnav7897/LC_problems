class Solution {
public:
    int solve(vector<vector<int>>& o , int i , int j , vector<vector<int>> &dp){
        int n = o.size();
        int m = o[0].size();
        if(i == 0 && j == 0){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(i>0 && o[i-1][j] != 1){
            ans+=solve(o , i-1 , j , dp);
        }
        if(j>0 && o[i][j-1] != 1){
            ans+= solve(o , i , j-1 ,dp);
        }
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        if(o[0][0] == 1 || o[n-1][m-1] ==1){
            return 0;
        }
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        return solve(o ,n-1 , m-1,dp);
    }
};