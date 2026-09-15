class Solution {
public:
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

        string temp = s + arr[idx];
        int ans = INT_MIN;
        if(unique(temp)){
            return max(solve(arr, idx+1 , temp) , solve(arr,idx+1,s));
        }
        return solve(arr, idx+1 , s);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        return solve(arr, 0 , "");
    }
};