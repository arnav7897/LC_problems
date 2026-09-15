class Solution {
public:

    int solve(vector<int>& j, int idx,int d , vector<vector<int>>& dp){
        int n = j.size();
        if(d == 1){
            int m = INT_MIN;
            for(int i = idx ; i<n ;i++){
                m = max(m , j[i]);
            }
            return m;
        }
        if(dp[idx][d] != -1){
            return dp[idx][d];
        }

        int maxi = INT_MIN;
        int ans = INT_MAX;
        for(int i = idx ; i<n - d +1;i++){
            maxi = max(maxi , j[i]);
            int result = maxi + solve(j , i+1 , d-1 , dp);
            ans = min(ans , result);
        }

        return dp[idx][d] = ans; 
    }

    int minDifficulty(vector<int>& j, int d) {
        int n = j.size();
        if(d > n){
            return -1;
        }
        vector<vector<int>> dp(n+1 , vector<int>(d+1, -1));
        int ans;
        ans = solve(j , 0 , d , dp);
        return ans;
    }
};