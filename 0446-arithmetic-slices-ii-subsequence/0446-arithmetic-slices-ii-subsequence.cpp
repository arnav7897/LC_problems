class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, long long>> dp(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 1LL * nums[i] - nums[j];
                ans += dp[j][d];
                dp[i][d] += dp[j][d] + 1;
            }
        }
        return ans;
    }
};