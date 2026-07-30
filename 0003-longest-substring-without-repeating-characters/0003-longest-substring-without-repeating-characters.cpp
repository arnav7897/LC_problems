class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        set<char> st;

        while (r < n) {
            if (st.find(s[r]) == st.end()) {
                st.insert(s[r]);
                ans = max(ans, r - l + 1);
                r++;
            } else {
                st.erase(s[l]);
                l++;
            }
        }

        return ans;
    }
};