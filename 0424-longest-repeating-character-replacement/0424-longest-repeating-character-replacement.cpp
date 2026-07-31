class Solution {
public:
    bool check(unordered_map<char,int>&f , int k){
        if(f.size() == 1){
            return false;
        }
        int maxi = INT_MIN;
        int s = 0; 
        for(auto&[a,b]:f){
            s+=b;
            maxi = max(maxi , b);
        }
        return s-maxi > k;
    }
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int n = s.length();
        int ans = 0;

        unordered_map<char,int> f;

        while(r<n){
            f[s[r]]++;
            if(check(f,k)){
                while(check(f,k)){
                    f[s[l]]--;
                    if(f[s[l]] == 0){
                        f.erase(s[l]);
                    }
                    l++;
                }
            }
            ans = max(ans , r - l+1);
            r++;
        }   
        return ans;
    }
};