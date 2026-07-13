class Solution {
public:
    unordered_map<string , bool> dp;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)==0){
            return true;
        }
        if(s1.length() <= 1){
            return false;
        }
        if(dp.find(s1+"#"+s2) != dp.end()){
            return dp[s1+"#"+s2];
        }
        int n = s1.length();
        bool flag = false;
        for(int k = 1 ;k<n;k++){
            bool s = isScramble(s1.substr(0,k) , s2.substr(0,k)) && isScramble(s1.substr(k) , s2.substr(k));
            bool ns = isScramble(s1.substr(0,k) , s2.substr(n-k)) && isScramble(s1.substr(k) , s2.substr(0,n-k));
            if(s || ns == true){
                flag = true;
                break;
            }
        }
        return dp[s1+"#"+s2] = flag;
    }
};