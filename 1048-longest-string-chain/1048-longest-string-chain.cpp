class Solution {
public:
    static bool cmp(const string &a, const string &b) {
        return a.length() < b.length();
    }

    bool pred(string &a, string &b) {
        if (b.length() != a.length() + 1)
            return false;

        int i = 0, j = 0;

        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }

        return i == a.length();
    }

    int longestStrChain(vector<string>& w) {
        sort(w.begin(), w.end(), cmp);

        int n = w.size();
        int maxi = 1;

        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pred(w[j], w[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};