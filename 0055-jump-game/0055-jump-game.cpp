class Solution {
public:
    bool solve(vector<int>& nums, int idx, vector<int>& dp) {
        int n = nums.size();
        if (idx == n - 1)
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        bool ans = false;
        for (int i = 1; i <= nums[idx] && idx + i < n; i++) {
            ans = ans || solve(nums, idx + i, dp);
        }
        return dp[idx] = ans;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(nums, 0, dp);
    }
};