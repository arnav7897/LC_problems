class Solution {
public:
    int help(int idx , vector<int>& cost , vector<int>&dp ){
        if(idx >= cost.size()){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        int c1 = cost[idx]+help(idx+1 , cost , dp);
        int c2 = cost[idx]+help(idx+2 , cost , dp);

        return dp[idx] = min(c1 ,c2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        return min(help(0,cost , dp) , help(1 , cost , dp));
    }
};