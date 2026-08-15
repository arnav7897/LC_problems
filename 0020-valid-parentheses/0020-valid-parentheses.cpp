class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i<s.length();i++){
            bool empty = false;
            char top = '0';
            if(st.empty()){
                empty = true;
            }else{
                top = st.top();
            }
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == '{'){
                st.push(s[i]);
            }else if(s[i] == '['){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(empty || top != '('){
                    return false;
                }else{
                    st.pop();
                }
            }else if(s[i] == ']'){
                if(empty || top != '['){
                    return false;
                }else{
                    st.pop();
                }
            }else{
                if(empty || top!='{'){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};