class Solution {
public:
    int solve(vector<pair<pair<int,int>, int>>& pt, int idx, vector<int>& dp) {
        int n = pt.size();

        if (idx == n) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int skip = solve(pt, idx + 1, dp);

        int start = pt[idx].first.first;
        int end = pt[idx].first.second;
        int cost = pt[idx].second;

        int lo = idx + 1;
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (pt[mid].first.first >= end) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        int take = cost + solve(pt, lo, dp);

        return dp[idx] = max(skip, take);
    }

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = s.size();

        vector<pair<pair<int,int>, int>> pt;

        for (int i = 0; i < n; i++) {
            pt.push_back({{s[i], e[i]}, p[i]});
        }

        sort(pt.begin(), pt.end());

        vector<int> dp(n, -1);

        return solve(pt, 0, dp);
    }
};