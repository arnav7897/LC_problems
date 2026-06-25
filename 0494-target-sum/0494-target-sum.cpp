class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // options either make it - or +ve
        int sum = accumulate(nums.begin() ,nums.end() , 0);
        if(abs(target)>sum){
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(2*sum +1 ,0));
        int offset = sum;
        dp[n][offset] = 1;
       for (int i = n - 1; i >= 0; i--) {
    for (int t = -sum; t <= sum; t++) {

        int way = 0;

        if (t + nums[i] <= sum)
            way += dp[i + 1][t + nums[i] + offset];

        if (t - nums[i] >= -sum)
            way += dp[i + 1][t - nums[i] + offset];

        dp[i][t + offset] = way;
    }
}
        return dp[0][offset+target]; 
    }
};