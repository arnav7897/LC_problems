class Solution {
public:
    // int help(vector<int>& c , vector<vector<int>>&dp , int s , int a){
    //     if(a==0){
    //         return 0;
    //     }

    //     if(s == 0){
    //         return 1e9;
    //     }

    //     if(dp[s][a] != -1){
    //         return dp[s][a];
    //     }

    //     int c2 = INT_MAX;
    //     int c1 = help(c , dp , s-1 , a);

    //     if(a >= c[s-1]){
    //         c2 = 1 + help(c, dp , s , a-c[s-1]);
    //     }

    //     return dp[s][a] = min(c1 , c2);
    // }
    int coinChange(vector<int>& c, int a) {
        int n = c.size();
        vector<vector<int>> dp(n + 1, vector<int>(a + 1, -1));
        for (int i = 0; i <= a; i++) {
            dp[0][i] = 1e9;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= a; j++) {
                int take = 1e9;
                int notake = dp[i-1][j];
                if(j >= c[i-1]){
                    take = 1 + dp[i][j-c[i-1]];
                }
                dp[i][j] = min(take , notake);
            }
        }
        if(dp[n][a] == 1e9){
            return -1;
        }
        return dp[n][a];
    }
};