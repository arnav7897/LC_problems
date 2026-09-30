class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string ans;
        for(auto &it: s){
            if(it=='*'){
                if(st.empty()){
                    continue;
                }else{
                    st.pop();
                }
            }else{
            st.push(it);
            }
        }
        while(!st.empty()){
            char t = st.top();
            ans.push_back(t);
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};