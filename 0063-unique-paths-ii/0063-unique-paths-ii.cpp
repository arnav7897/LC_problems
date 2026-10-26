class Solution {
public:
    // int solve(vector<vector<int>>& o , int i , int j , vector<vector<int>> &dp){
    //     int n = o.size();
    //     int m = o[0].size();
    //     if(i == 0 && j == 0){
    //         return 1;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     int ans = 0;
    //     if(i>0 && o[i-1][j] != 1){
    //         ans+=solve(o , i-1 , j , dp);
    //     }
    //     if(j>0 && o[i][j-1] != 1){
    //         ans+= solve(o , i , j-1 ,dp);
    //     }
    //     return dp[i][j] = ans;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        if(o[0][0] == 1 || o[n-1][m-1] == 1){
            return 0;
        }
        vector<vector<int>> dp(n , vector<int>(m , 0));
        dp[0][0] = 1;
        for(int i =0;i<n ;i++){
            for(int j = 0; j<m ;j++){
                if(i>0 && o[i-1][j]!=1){
                    dp[i][j] += dp[i-1][j];
                }
                if(j>0 && o[i][j-1]!=1){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};