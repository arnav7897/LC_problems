class Solution {
public:
    int solve(int a , vector<int>& c , int i , vector<vector<int>>&dp){
        if(i == 0){
            if(a%c[0] == 0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][a]!=-1){
            return dp[i][a];
        }
        if(a >= c[i]){
            return dp[i][a] = solve(a,c,i-1,dp) + solve(a-c[i] , c , i ,dp);
        }
        return dp[i][a] = solve(a,c,i-1,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount +1 , -1));
        return solve(amount , coins , n-1 , dp);
    }
};