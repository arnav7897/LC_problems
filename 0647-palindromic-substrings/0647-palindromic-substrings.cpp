class Solution {
public:
    bool ispail(string s, int l, int r) {
        for(int i = 0; i < (r-l+1)/2; i++) {
            if(s[l+i] != s[r-i]) {
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0 ; i<=n-1; i++){
            int l = 0;
            int r = l + i;
            while(r < n){
                if(ispail(s,l,r)){
                    ans++;
                }
                l++;
                r++;
            }
        }
        return ans;
    }
};