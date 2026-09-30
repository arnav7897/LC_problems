class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto &it: s){
            int n = ans.length();
            if(it=='*'){
                if(n == 0){
                    continue;
                }else{
                    ans.pop_back();
                }
            }else{
                ans.push_back(it);
            }
        }
        return ans;
    }
};