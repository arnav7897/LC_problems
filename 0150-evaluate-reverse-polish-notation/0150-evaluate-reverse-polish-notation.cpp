class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &s : tokens){
            if(s=="+"){
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o1 + o2);
            }else if(s == "-"){
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o2 - o1);
            }else if(s == "*"){
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o1 * o2);
            }else if(s == "/"){
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o2/o1);
            }else{
                int t = stoi(s);
                st.push(t);
            }
        }   
        return st.top(); 
    }
};