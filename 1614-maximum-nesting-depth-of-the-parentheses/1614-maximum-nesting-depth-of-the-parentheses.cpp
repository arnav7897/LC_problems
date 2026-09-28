class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int ans = 0;
        for(auto&it : s){
            if(it == '('){
                st.push(it);
                int s = st.size();
                ans = max(ans , s);
            }else if(it == ')'){
                st.pop();
            }
        }
        return ans;
        }
};