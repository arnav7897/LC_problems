class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , 0);
        dp[0] = 1;
        for(int i = 1 ;i<=n ;i++){
            int ans = dp[i-1];
            if(i>=2){
                ans += dp[i-2];
            }   
            dp[i] = ans;
        }

        return dp[n];
    }
};