class Solution {
public:
    int help(vector<int>& nums , int idx , vector<int>&dp){
        int n = nums.size();
        if(idx >= n-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans = INT_MAX;
        for(int i =1 ;i<=nums[idx] && idx + i < n;i++){
            int next = help(nums , idx+i , dp);
            if(next == INT_MAX){
                continue;
            }
            ans = min(ans , 1+next);
        }
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n+1,-1);
        return help(nums , 0  , dp);
    }
};