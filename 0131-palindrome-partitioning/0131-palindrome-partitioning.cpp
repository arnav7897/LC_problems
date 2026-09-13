class Solution {
public:
    bool ispal(string s){
        int n = s.length();
        for(int i =0 ;i< n; i++){
            if(s[i] != s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans,vector<string> &a , int idx , string s){
        int n = s.length();

        if(idx == n){
            ans.push_back(a);
            return;
        }

        for(int i = idx ; i<n ;i++){
            string temp = s.substr(idx , i-idx+1);
            if(ispal(temp)){
                a.push_back(temp);
                solve(ans , a , i+1, s);
                a.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.length();
        vector<string> a;
        solve(ans,a,0,s);
        return ans;
    }
};