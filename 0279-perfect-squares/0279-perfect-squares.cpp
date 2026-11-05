class Solution {
public:
    int numSquares(int num) {
        int length = sqrt(num) + 1;

        vector<vector<int>> memo(length + 1, vector<int>(num + 1, -1));

        function<int(int, int)> solve = [&](int i, int n) -> int {
            if (n == 0) {
                return 0;
            }

            if (i >= length || n < 0) {
                return INT_MAX / 2;
            }

            if (memo[i][n] != -1) {
                return memo[i][n];
            }

            int take = INT_MAX / 2;

            if (n - i * i >= 0) {
                take = 1 + solve(i, n - i * i);
            }

            int skip = solve(i + 1, n);

            memo[i][n] = min(take, skip);

            return memo[i][n];
        };

        return solve(1, num);
    }
};