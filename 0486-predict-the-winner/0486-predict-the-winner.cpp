class Solution {
public:
    int help(vector<int>& nums , vector<vector<int>>&dp , int s , int e){
        if(s > e){
            return 0;
        }
        if(s == e){
            return nums[s];
        }
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int t1 = nums[s] + min(help(nums , dp , s+1 , e-1) , help(nums , dp , s+2 , e));
        int t2 = nums[e] + min(help(nums, dp , s+1 , e-1) , help(nums , dp,s , e-2));

        return dp[s][e] = max(t1 , t2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum = 0;
        int n= nums.size();
        for(int i =0 ;i<n;i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(n , vector<int>(n , -1));
        int a = help(nums , dp , 0 , n-1);
        return sum <= 2*a;
    }
};