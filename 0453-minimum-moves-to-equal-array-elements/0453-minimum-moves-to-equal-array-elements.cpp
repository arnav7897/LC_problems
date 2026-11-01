class Solution {
public:
    int minMoves(vector<int>& nums) {
        unordered_map<int, int> m;
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            m[nums[i]]++;     
            mini = min(mini , nums[i]);
        }
        int ans = 0;
        for(auto &it : m){
            if(mini != it.first){
                ans += it.second*(it.first - mini);
            }
        }
        return ans;
    }
};