class Solution {
public:
    unordered_map<string , int> dp;
    bool unique(string s){
        vector<int> f(26,0);
        for(auto&ch : s){
            f[ch-'a']++;
            if(f[ch-'a']>1){
                return false;
            }
        }
        return true;
    }
    int solve(vector<string>& arr , int idx , string s){
        int n = arr.size();
        if(idx == n){
            return s.length();
        }
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        string temp = s + arr[idx];
        int ans = INT_MIN;
        if(unique(temp)){
            return dp[s] = max(solve(arr, idx+1 , temp) , solve(arr,idx+1,s));
        }
        return dp[s] = solve(arr, idx+1 , s);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        dp.clear();
        return solve(arr, 0 , "");
    }
};