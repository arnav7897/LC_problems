class Solution {
public:
    int help(vector<int>& c , vector<vector<int>>&dp , int s , int a){
        if(a==0){
            return 0;
        }

        if(s == 0){
            return 1e9;
        }
        
        if(dp[s][a] != -1){
            return dp[s][a];
        }

        int c2 = INT_MAX;
        int c1 = help(c , dp , s-1 , a);
        
        if(a >= c[s-1]){
            c2 = 1 + help(c, dp , s , a-c[s-1]);
        }
        
        return dp[s][a] = min(c1 , c2);
    }
    int coinChange(vector<int>& c, int a) {
        int n = c.size();
        vector<vector<int>> dp(n+1 , vector<int>(a+1, -1));
        int ans = help(c , dp , n , a);
        return (ans >= 1e9) ? -1 : ans; 
   }
};