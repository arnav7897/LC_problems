class Solution {
public: 
    int solve(vector<int>& nums , int curr , int prev , vector<vector<int>>&dp){
        int n = nums.size();
        if(curr >= n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int take = INT_MIN , skip = INT_MIN;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1+solve(nums , curr +1 , curr,dp);
        }
        skip = solve(nums , curr+1 , prev ,dp);
        return dp[curr][prev+1] = max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        return solve(nums , 0 , -1 , dp);
    }
};