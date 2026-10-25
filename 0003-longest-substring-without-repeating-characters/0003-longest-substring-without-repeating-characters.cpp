class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int r = 0; 
       int l = 0;
       int n = s.length();
       unordered_map<char , int> mp;
       int ans = 0;
       while(r < n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                ans = max(r-l , ans);
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
       } 
       ans = max(ans , r-l);
       return ans;
    }
};