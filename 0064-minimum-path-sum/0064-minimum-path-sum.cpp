class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = a[0][0];
        for(int i = 0 ; i<m;i++){
            for(int j = 0 ;j<n;j++){
                int up = INT_MAX;
                int right = INT_MAX;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    right = dp[i][j-1];
                }
                dp[i][j]=min(right ,up);
                if(dp[i][j] == INT_MAX){
                    dp[i][j] = 0;
                }
                dp[i][j] += a[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};