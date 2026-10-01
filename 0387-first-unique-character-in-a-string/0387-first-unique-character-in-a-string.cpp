class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26,0);
        for(auto &it : s){
            f[it-'a']++;
        }   
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(f[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};