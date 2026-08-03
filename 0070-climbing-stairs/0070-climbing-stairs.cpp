class Solution {
public:
    int help(int n , vector<int>&dp){
        if(n <=2 ){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        int c1 = help(n-1 , dp);
        int c2 = help(n-2 , dp);

        return dp[n] = c1+c2;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return help(n , dp);
    }
};