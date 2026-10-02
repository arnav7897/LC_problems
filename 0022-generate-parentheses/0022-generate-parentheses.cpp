class Solution {
public:
    void solve(vector<string> &ans ,int n, int l , int r ,string s){
        if(l - r < 0 || l>n || r>n){
            return ;
        }

        if(l == n && r == n){
            ans.push_back(s);
            return ;
        }

        if(l-r == 0){
            s.push_back('(');
            solve(ans , n, l+1 ,r,s);
        }else{
            s.push_back('(');
            solve(ans , n , l+1 ,r , s);
            s.pop_back();
            s.push_back(')');
            solve(ans , n , l , r+1 , s);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans , n , 0 , 0, "");
        return ans;
    }
};