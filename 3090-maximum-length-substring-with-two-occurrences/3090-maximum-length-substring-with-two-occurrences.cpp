class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> a(26,0);
        int r = 0;
        int l = 0;
        int ans = 0;
        while(r<n){
            a[s[r] - 'a']++;
            while(a[s[r] - 'a'] >2){
                a[s[l] - 'a']--;
                l++;
            }
            ans = max(ans , r-l+1);
            r++;
        }
        return ans;
    }
};