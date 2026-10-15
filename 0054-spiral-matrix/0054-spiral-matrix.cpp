
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int u = 0, d = n - 1;
        int l = 0, r = m - 1;

        vector<int> ans;

        while (u <= d && l <= r) {
            // Left to right
            for (int j = l; j <= r; j++) {
                ans.push_back(mat[u][j]);
            }
            u++;

            // Top to bottom
            for (int i = u; i <= d; i++) {
                ans.push_back(mat[i][r]);
            }
            r--;

            // Right to left
            if (u <= d) {
                for (int j = r; j >= l; j--) {
                    ans.push_back(mat[d][j]);
                }
                d--;
            }

            // Bottom to top
            if (l <= r) {
                for (int i = d; i >= u; i--) {
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
        }

        return ans;
    }
};
