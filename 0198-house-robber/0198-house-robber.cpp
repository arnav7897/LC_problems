class Solution {
public:
    int solve(vector<int>& nums , int idx , vector<int>&dp){
        int n = nums.size();
        
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int ans = max(solve(nums , idx+1 , dp) , solve(nums , idx +2 , dp) + nums[idx]);

        return dp[idx] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , -1);
        return solve(nums , 0 , dp);
    }
};