class Solution {
public:
    int solve(vector<int>& p, int i, int hold, int chances,
              vector<vector<vector<int>>>&dp) {
        if (i == p.size()) {
            return 0;
        }
        if (chances == 0) {
            return 0;
        }
        if (dp[i][hold][chances] != -1) {
            return dp[i][hold][chances];
        }
        // 2 cases for hold
        if (hold) {
            return dp[i][hold][chances] =
                       max(solve(p, i + 1, hold, chances, dp),
                           solve(p, i + 1, 0, chances - 1, dp) + p[i]);
        } else {
            return dp[i][hold][chances] =
                       max(solve(p, i + 1, hold, chances, dp),
                           solve(p, i + 1, 1, chances, dp)-p[i]);
        }
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(p, 0, 0, 2, dp);
    }
};
