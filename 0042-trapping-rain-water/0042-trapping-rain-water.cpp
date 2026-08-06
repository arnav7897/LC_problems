class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = h[0];
        for(int i =1 ;i<n;i++){
            pre[i] = max(h[i] , pre[i-1]);
        }
        suf[n-1] = h[n-1];
        for(int i = n-2 ;i >= 0 ;i--){
            suf[i] = max(suf[i+1] , h[i]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(min(suf[i] , pre[i]) >= h[i] ){
                ans += min(suf[i] , pre[i]) - h[i]; 
            }
        }
        return ans;
    }
};