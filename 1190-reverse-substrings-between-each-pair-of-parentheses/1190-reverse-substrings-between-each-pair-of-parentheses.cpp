class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int i = 0;
        for(auto &it : s){
            if(it == '('){
                st.push(i);
            }else if(it == ')'){
                int top = st.top();
                st.pop();
                reverse(s.begin() + top + 1 , s.begin() + i); 
            }
            i++;
        }
        string ans = "";
        for(auto &it : s){
            if(it != '(' && it != ')'){
                ans.push_back(it);
            }
        }
        return ans;
    }
};