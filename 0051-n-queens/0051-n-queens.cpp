class Solution {
public:

    bool put(vector<vector<int>> &a, int i, int j) {
        for (int row = 0; row < i; row++) {
            if (a[row][j] == 1)
                return false;
        }
        for (int row = i - 1, col = j - 1;
             row >= 0 && col >= 0;
             row--, col--) {

            if (a[row][col] == 1)
                return false;
        }
        for (int row = i - 1, col = j + 1;
             row >= 0 && col < a.size();
             row--, col++) {

            if (a[row][col] == 1)
                return false;
        }

        a[i][j] = 1;
        return true;
    }

    void solve(vector<vector<string>> &ans,
               vector<vector<int>> &a,
               int n,
               int idx) {

        if (idx == n) {

            vector<string> temp;

            for (int i = 0; i < n; i++) {
                string s;

                for (int j = 0; j < n; j++) {
                    if (a[i][j] == 1)
                        s += 'Q';
                    else
                        s += '.';
                }

                temp.push_back(s);
            }

            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {

            if (put(a, idx, i)) {

                solve(ans, a, n, idx + 1);
                a[idx][i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<vector<int>> a(
            n,
            vector<int>(n, 0)
        );

        solve(ans, a, n, 0);

        return ans;
    }
};