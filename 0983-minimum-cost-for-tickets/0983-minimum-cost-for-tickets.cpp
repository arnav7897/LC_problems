class Solution {
public:
    int mincostTickets(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();

        int max_expiry = nums[n-1] + 30;

        vector<vector<int>> dp(
            n + 1,
            vector<int>(max_expiry + 1, 0)
        );

        vector<int> days = {1, 7, 30};

        for(int i = n-1; i >= 0; i--) {

            for(int j = max_expiry; j >= 0; j--) {

                if(nums[i] <= j) {
                    dp[i][j] = dp[i+1][j];
                }
                else {
                    int ans = INT_MAX;

                    for(int p = 0; p < 3; p++) {

                        int newExpiry = nums[i] + days[p] - 1;

                        ans = min(ans,
                            costs[p] + dp[i+1][newExpiry]
                        );
                    }

                    dp[i][j] = ans;
                }
            }
        }

        return dp[0][0];
    }
};