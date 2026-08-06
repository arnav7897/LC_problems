class Solution {
public:
    using ll = long long;

    long long solve(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());

        int n = coins.size();
        ll ans = 0;
        ll cur = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            ll right = 1LL * coins[i][0] + k - 1;

            while (j < n && coins[j][1] <= right) {
                cur += 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            ll total = cur;

            if (j < n && coins[j][0] <= right) {
                ll overlap = right - coins[j][0] + 1;
                total += overlap * coins[j][2];
            }

            ans = max(ans, total);

            cur -= 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        return ans;
    }

    long long maximumCoins(vector<vector<int>>& coins, int k) {
        long long ans = solve(coins, k);

        for (auto& v : coins) {
            int l = v[0], r = v[1];
            v[0] = -r;
            v[1] = -l;
        }

        ans = max(ans, solve(coins, k));

        return ans;
    }
};
