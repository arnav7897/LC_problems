class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) { // ngr
        stack<int> st;
        int n = arr.size();
        vector<int> ngr(n);
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ngr[i] = 0;
            }else{
                ngr[i] = st.top() - i;
            }
            st.push(i);
        }
        return ngr;
    }
};