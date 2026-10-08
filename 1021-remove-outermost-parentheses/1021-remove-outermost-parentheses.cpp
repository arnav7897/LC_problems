class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int r = 1;
        int l = 0;
        int b = 1;
        int n = s.length();
        while(r<n){
            if(s[r] == ')'){
                b--;
            }else{
                b++;
            }
            if(b == 0){
                for(int i = l+1 ; i<r ;i++){
                    ans += s[i];
                }
                l = r+1;
            }
            r++;
        }
        return ans;
    }
};