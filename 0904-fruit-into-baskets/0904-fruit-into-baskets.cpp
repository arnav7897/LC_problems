class Solution {
public:
    int totalFruit(vector<int>& f) {
        int l = 0, r = 0;
        int ans = 0;
        int n = f.size();

        unordered_map<int, int> fq;

        while (r < n) {
            fq[f[r]]++;

            while (fq.size() > 2) {
                fq[f[l]]--;
                if (fq[f[l]] == 0)
                    fq.erase(f[l]);
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
