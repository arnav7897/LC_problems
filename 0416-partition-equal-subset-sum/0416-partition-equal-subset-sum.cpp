class Solution {
public:
    // bool solve(vector<int>& nums , int i , int t , int sum , vector<vector<int>>&dp){
    //     if(t == sum -t){
    //         return true;
    //     }
    //     if(i == nums.size()){
    //         return false;
    //     }

    //     if(dp[i][t] != -1){
    //         return dp[i][t];
    //     }

    //     // 2 choices for 1 either take or reject
    //     bool accept = solve(nums , i+1 , t+ nums[i] , sum ,dp);
    //     bool reject = solve(nums , i+1 , t , sum , dp);
    //     return dp[i][t] = accept || reject;
    // }

bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();

    for(int x : nums){
        sum += x;
    }

    if(sum % 2){
        return false;
    }

    int target = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for(int i =0 ;i<=n;i++){
        dp[i][target] = 1;
    }

    for(int i = n-1; i >= 0; i--){
        for(int s = target; s >= 0; s--){

            int accept = 0;
            if(s + nums[i] <= target){
                accept = dp[i + 1][s + nums[i]];
            }

            int reject = dp[i + 1][s];

            dp[i][s] = accept || reject;
        }
    }

    return dp[0][0];
}

};