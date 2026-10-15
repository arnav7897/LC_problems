class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0;
        int j = 0;
        int maxi = 0;
        int r = 0;

        for(int i = 0 ;i<n ;i++){
            int c = 0;
            for(int j = 0;j<m ;j++){
                if(mat[i][j] == 1){
                    c++;
                }
            }
            if(maxi < c){
                maxi = c;
                r = i;
            }
        }

        return {r,maxi};   
    }
};