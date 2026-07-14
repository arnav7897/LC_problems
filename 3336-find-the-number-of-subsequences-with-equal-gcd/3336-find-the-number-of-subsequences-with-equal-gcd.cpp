class Solution {
public:
    const int MOD = 1e9 + 7;

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long long solve(vector<int>& nums, int i, int g1, int g2,
                    vector<vector<vector<long long>>>& dp) {

        if (i == 0) {
            return (g1 == g2 && g1 != 0);
        }

        if (dp[i][g1][g2] != -1) {
            return dp[i][g1][g2];
        }

        return dp[i][g1][g2] =
                   (solve(nums, i - 1, g1, g2, dp) +
                    solve(nums, i - 1, gcd(g1, nums[i - 1]), g2, dp) +
                    solve(nums, i - 1, g1, gcd(g2, nums[i - 1]), dp)) %
                   MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(mx + 1, vector<long long>(mx + 1, -1)));

        return solve(nums, n, 0, 0, dp);
    }
};
