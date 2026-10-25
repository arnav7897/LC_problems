
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = m - 1;
        int u = 0, d = n - 1;

        vector<int> spiral;

        while (l <= r && u <= d) {
            // Left to right
            for (int i = l; i <= r; i++) {
                spiral.push_back(matrix[u][i]);
            }
            u++;

            // Top to bottom
            for (int i = u; i <= d; i++) {
                spiral.push_back(matrix[i][r]);
            }
            r--;

            // Right to left
            if (u <= d) {
                for (int i = r; i >= l; i--) {
                    spiral.push_back(matrix[d][i]);
                }
                d--;
            }

            if (l <= r) {
                for (int i = d; i >= u; i--) {
                    spiral.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return spiral;
    }
};
