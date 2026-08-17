class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> f;

        for (auto& c : tasks) {
            f[c]++;
        }

        priority_queue<int> pq;

        for (auto [a, b] : f) {
            pq.push(b);
        }

        int ans = 0;

        while (!pq.empty()) {
            vector<int> save;

            for (int i = 0; i <= n; i++) {

                if (pq.empty()) {
                    if (!save.empty()) {
                        ans += (n - i + 1);
                    }
                    break;
                }

                int t = pq.top();
                pq.pop();

                ans++;

                if (t - 1 > 0) {
                    save.push_back(t - 1);
                }
            }

            for (auto x : save) {
                pq.push(x);
            }
        }

        return ans;
    }
};