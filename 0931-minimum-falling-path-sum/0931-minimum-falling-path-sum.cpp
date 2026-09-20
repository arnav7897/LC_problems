class Solution {
public:
    // int solve(vector<vector<int>>& mat , int i , int j , vector<vector<int>>&dp){
    //     int n = mat.size();
    //     int m = mat[0].size();
        
    //     if(i<0 || j<0 || i>=n || j>=m){
    //         return INT_MAX;
    //     }
    //     if(i == n-1){
    //         return mat[i][j]; 
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     return dp[i][j] = min(solve(mat , i+1 , j-1 ,dp) , min(solve(mat,i+1,j,dp) , solve(mat, i+1 , j+1 ,dp))) + mat[i][j];
    // }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int ans = INT_MAX;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

        for(int i = 0; i<m;i++){
            dp[n-1][i] = mat[n-1][i];
        }

        int dx[] = {1 , 1 ,1 };
        int dy[] = {-1 ,0 ,1}; 

        for(int i = n-2 ; i>=0 ;i--){
            for(int j = 0; j<m ;j++){
                int ans = INT_MAX;
                for(int k = 0; k<3;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    int c; 
                    if(x<0 || y<0 || x>=n || y>=m){
                        c = INT_MAX;
                    }else{
                        c = dp[x][y];
                        ans = min(c , ans);
                    }
                }
                if(ans == INT_MAX){
                    dp[i][j] = INT_MAX;
                }else{
                    dp[i][j] = ans + mat[i][j];
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0; i< m ;i++){
            res = min(res , dp[0][i]);
        }
        return res;
    }
};