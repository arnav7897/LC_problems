class Solution {
public:
    int solve(vector<int> &c , int amt , int idx , vector<vector<int>> &dp){
        if(idx<0){
            if(amt == 0){
                return 0;
            }else{
                return INT_MAX;
            }
        }
        if(dp[idx][amt] != -1){
            return dp[idx][amt];
        }
        if(amt >= c[idx]){
            int accept = solve(c,amt-c[idx],idx,dp);
            if(accept != INT_MAX){
                accept++;
            }
            return dp[idx][amt] = min( solve(c,amt,idx-1 , dp) , accept);
        }
        return dp[idx][amt] = solve(c,amt,idx-1 , dp);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n ,vector<int> (amount+1,-1) );
        int ans = solve(coins , amount , n-1 , dp);
        if(ans == INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }   
};