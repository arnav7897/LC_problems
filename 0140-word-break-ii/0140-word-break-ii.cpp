class Solution {
public:

    bool match(string s,vector<string>& w){
        for(auto & it : w){
            if(s == it){
                return true;
            }
        }
        return false;
    }

    void solve(vector<string>& ans , string &a, int idx , string &s , vector<string>& w){
        int n = s.length();
        if(idx == n){
            ans.push_back(a);
            return;
        }

        for(int i = idx ; i<n ;i++){
            string temp = s.substr(idx , i - idx + 1);
            string temp2 = a;
            if(match(temp , w)){
                if(a.length() != 0){
                    a += " ";
                }
                a += temp; 
                solve(ans , a , i+1 , s , w);
                a = temp2;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& w) {
        vector<string> ans;
        string a = "";
        solve(ans ,a,0 , s , w);
        return ans;
    }
};