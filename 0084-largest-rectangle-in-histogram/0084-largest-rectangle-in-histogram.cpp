class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> nsl(n);
        vector<int> nsr(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(st.empty()){
                nsl[i] = -1; 
            }else{
                nsl[i] = st.top(); 
            }
            st.push(i);
        } 
        st = {};
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && h[st.top()] >= h[i]){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = n; 
            }else{
                nsr[i] = st.top(); 
            }
            st.push(i);
        } 
        int ans = INT_MIN;
        for(int i =0 ;i<n;i++){
            ans = max(ans , h[i]*(nsr[i] - nsl[i]-1));
        }
        return ans;
    }
};