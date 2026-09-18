class Solution {
public:

    static bool cmp(const pair<pair<int, int>, int>& a,
                    const pair<pair<int, int>, int>& b) {

        return a.first.second < b.first.second;
    }

    vector<int> getOrder(vector<vector<int>>& t) {

        int n = t.size();

        vector<pair<pair<int, int>, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({{t[i][1], t[i][0]}, i});
        }

        sort(a.begin(), a.end(), cmp);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans;

        long long curr = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            if (pq.empty()) {
                curr = max(curr, (long long)a[i].first.second);
            }

            while (i < n && a[i].first.second <= curr) {
                pq.push({a[i].first.first, a[i].second});
                i++;
            }

            auto [processingTime, idx] = pq.top();
            pq.pop();

            curr += processingTime;
            ans.push_back(idx);
        }

        return ans;
    }
};