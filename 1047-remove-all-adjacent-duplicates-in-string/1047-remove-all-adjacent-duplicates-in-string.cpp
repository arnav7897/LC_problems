class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for(char ch : s){
            if(st.empty()){
                st.push(ch);
            }
            else if(st.top() == ch){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()){
            char a = st.top();
            ans += a;
            st.pop();
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};