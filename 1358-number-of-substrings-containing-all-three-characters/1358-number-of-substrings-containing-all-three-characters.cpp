class Solution {
public:
// we have to do total no. of substring - no. of subsrting not having all the frequency;
    int numberOfSubstrings(string s) {
        int l=0,r=0,n=s.length();
        long long ans =0;
        vector<int> f(3,0);
        while(r<n){
            f[s[r]-'a']++;
            while(f[0] && f[1] && f[2]){
                f[s[l]-'a']--;
                l++;
            }
            ans += r-l+1;
            r++;
        }
        long long all = 1ll*n*(n+1)/2;
        return static_cast<int>(all - ans);
    }
};