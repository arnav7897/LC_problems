class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int z = 0;
        int l = 0, r = 0;
        int n = a.size();
        int ans = 0;

        while (r < n) {
            if (a[r] == 0) z++;         
            while (z > k) {         
                if (a[l] == 0) z--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
