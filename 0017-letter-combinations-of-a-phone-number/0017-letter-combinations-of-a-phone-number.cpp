class Solution {
public:

    void solve(string &d , vector<string> &ans , string &s , vector<string> &a , int idx){
        int n = d.length();
        if(idx == n){
            ans.push_back(s);
            return;
        }

        // loop
        for(auto &ch : a[(d[idx] - '0') - 2]){
            s.push_back(ch);
            solve(d,ans,s,a,idx+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> a(8);
        a[0] ="abc";
        a[1] ="def";
        a[2] ="ghi";
        a[3] ="jkl";
        a[4] ="mno";
        a[5] ="pqrs";
        a[6] ="tuv";
        a[7] ="wxyz";

        vector<string> ans;
        string s = "";

        solve(digits , ans , s , a , 0);
        return ans;
    }
};