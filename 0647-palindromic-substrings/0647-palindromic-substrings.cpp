class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n= s.length();
        for(int c = 0 ;c<n ;c++){
            // odd length
            int r = c;
            int l = c;
            while(r<n && l>=0 && s[l] == s[r]){
                ans++;
                r++;
                l--;
            }
            // even length
            r=c+1;
            l=c;
            while(r<n && l>=0 && s[l] == s[r]){
                ans++;
                r++;
                l--;
            }
        }      
        return ans;
    }
};