class Solution {
public:
    int help(vector<int>& a, int m) {
        int p = 0, c = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (p + a[i] > m) {
                c++;
                p = a[i];
            } else {
                p += a[i];
            }
        }
        return c;
    }
    int splitArray(vector<int>& a, int k) {
        int s = INT_MIN;
        int e = 0;
        for (auto& it : a) {
            s = max(s, it);
            e += it;
        }
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (help(a, m) >= k) {
                s = m + 1;
            } else {
                e = m - 1;
            }
        }
        return s;
    }
};