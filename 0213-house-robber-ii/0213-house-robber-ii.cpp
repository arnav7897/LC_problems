class Solution {
public:
    int help(vector<int>& nums , vector<int>&dp , int s , int e){
        if(s > e){
            return 0;
        }
        if(dp[s] != -1){
            return dp[s];
        }
        return dp[s] = max(nums[s] + help(nums , dp , s+2 ,e) , help(nums , dp , s+1 , e));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[n-1];
        }
        vector<int> dp1(n , -1) , dp2(n , -1);
        return max(help(nums , dp1 , 0 , n-2) , help(nums , dp2 , 1 , n-1));
    }
};