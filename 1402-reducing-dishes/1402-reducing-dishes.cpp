class Solution {
public:
    // int solve(vector<int>& sat , int idx , int till){
    //     int n = sat.size();
    //     if(idx == n){
    //         return 0;
    //     }
    //     // 2 option skip or take 
    //     return max(solve(sat , idx +1 , till+1)+sat[idx]*till ,solve(sat , idx +1 , till));
    // }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin() , sat.end());
        int n = sat.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

        for(int i = n-1 ;i>=0 ;i--){
            for(int j = n-1 ; j>=0 ;j--){
                dp[i][j] = max(dp[i+1][j+1] + (j+1)*sat[i] , dp[i+1][j]);  
            }
        }

        return dp[0][0];
    }
};