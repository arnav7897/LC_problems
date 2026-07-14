class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int hold = 0; hold <= 1; hold++) {
                for (int chances = 1; chances <= 2; chances++) {

                    if (hold) {
                        dp[i][hold][chances] =
                            max(dp[i + 1][1][chances],
                                p[i] + dp[i + 1][0][chances - 1]);
                    } else {
                        dp[i][hold][chances] =
                            max(dp[i + 1][0][chances],
                                -p[i] + dp[i + 1][1][chances]);
                    }
                }
            }
        }

        return dp[0][0][2];
    }
};
