class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto it : nums){
            st.insert(it);
        }
        int ans =0;
        for(auto &it : st){
            int temp = 0;
            if(st.find(it-1) == st.end()){
                int t = it;
                while(st.find(t) != st.end()){
                    temp++;
                    t++;
                }
            }
            ans = max(ans , temp);
        }
        return ans;
    }
};