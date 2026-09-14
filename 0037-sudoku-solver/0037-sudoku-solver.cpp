class Solution {
public:

    bool valid(int i, int j, char num, vector<vector<char>>& b) {
        for(int k = 0; k < 9; k++) {
            if(b[i][k] == num)
                return false;
        }
        for(int k = 0; k < 9; k++) {
            if(b[k][j] == num)
                return false;
        }
        int r = (i / 3) * 3;
        int c = (j / 3) * 3;

        for(int x = r; x < r + 3; x++) {
            for(int y = c; y < c + 3; y++) {
                if(b[x][y] == num)
                    return false;
            }
        }
        return true;
    }

    bool solve(int i, int j, vector<vector<char>>& b) {
        if(i == 9)
            return true;
        if(j == 9)
            return solve(i + 1, 0, b);
        if(b[i][j] != '.')
            return solve(i, j + 1, b);
        for(int k = 0; k < 9; k++) {
            char num = k + '1';
            if(valid(i, j, num, b)) {
                b[i][j] = num;
                if(solve(i, j + 1, b))
                    return true;
                b[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};