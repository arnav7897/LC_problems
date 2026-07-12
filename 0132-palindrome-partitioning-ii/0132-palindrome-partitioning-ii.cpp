class Solution {
public:
    bool pail(string &s, int l , int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int solve(string &s , int i , int j,vector<vector<int>> &dp){
        if(i == j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(pail(s,i,j)){
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i; k<j;k++){
            if(pail(s,i,k)){
                int cost = 1 + solve(s , k+1 , j,dp);
                ans = min(ans , cost);
            }
        }
        return dp[i][j] = ans;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(s,0,n-1,dp);
    }
};