class Solution {
public:
    static const int MOD = 1e9 + 7;
    
    int dp[51][101][51];

    int solve(int idx, int maxi, int s, int n, int m, int k) {
        if (idx == n) {
            return s == k;
        }

        if (s > k) {
            return 0;
        }

        if (dp[idx][maxi][s] != -1) {
            return dp[idx][maxi][s];
        }

        long long ans = 0;

        if (maxi > 0) {
            ans += 1LL * maxi *
                   solve(idx + 1, maxi, s, n, m, k);
        }
        for (int i = maxi + 1; i <= m; i++) {
            ans += solve(idx + 1, i, s + 1, n, m, k);
            ans %= MOD;
        }

        return dp[idx][maxi][s] = ans % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, n, m, k);
    }
};