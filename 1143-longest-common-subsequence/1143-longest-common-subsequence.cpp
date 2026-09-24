class Solution {
public:
    int solve(string &s1 , string &s2 , int i , int j,vector<vector<int>> &dp){
        int n = s1.length();
        int m = s2.length();
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1,s2,i+1,j+1,dp);
        }else{
            return dp[i][j] = max(solve(s1,s2,i+1,j,dp) , solve(s1,s2,i,j+1,dp));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n,vector<int>(m ,-1));
        return solve(s1,s2,0,0,dp);
    }
};