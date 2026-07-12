class Solution {
public:
    int solve(vector<int>&cut , int i , int j , vector<vector<int>>&dp){
        if(i > j){
            return 0;        
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k= i; k<=j ;k++){
            int  temp = solve(cut , i , k-1 ,dp) + solve(cut , k+1 , j ,dp) + cut[j+1] - cut[i-1];
            ans = min(ans , temp); 
        }
        return dp[i][j] = ans;
    }
    int minCost(int m, vector<int>& cuts) {
        int n = cuts.size();
        cuts.push_back(0);
        cuts.push_back(m);
        sort(cuts.begin() , cuts.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1 , -1));
        return solve(cuts,1,n,dp);
    }
};