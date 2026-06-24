class Solution {
public:
    bool solve(vector<int>& nums , int i , int t , int sum , vector<vector<int>>&dp){
        if(t == sum -t){
            return true;
        }
        if(i == nums.size()){
            return false;
        }

        if(dp[i][t] != -1){
            return dp[i][t];
        }

        // 2 choices for 1 either take or reject
        bool accept = solve(nums , i+1 , t+ nums[i] , sum ,dp);
        bool reject = solve(nums , i+1 , t , sum , dp);
        return dp[i][t] = accept || reject;
    }

    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            sum+=nums[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(sum+1 , -1));

        return solve(nums , 0 , 0 , sum , dp);
    }
};