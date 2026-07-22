class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int original = image[sr][sc];

        if (original == color)
            return image;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Down
            if (x + 1 < n && image[x + 1][y] == original) {
                image[x + 1][y] = color;
                q.push({x + 1, y});
            }

            // Up
            if (x - 1 >= 0 && image[x - 1][y] == original) {
                image[x - 1][y] = color;
                q.push({x - 1, y});
            }

            // Right
            if (y + 1 < m && image[x][y + 1] == original) {
                image[x][y + 1] = color;
                q.push({x, y + 1});
            }

            // Left
            if (y - 1 >= 0 && image[x][y - 1] == original) {
                image[x][y - 1] = color;
                q.push({x, y - 1});
            }
        }

        return image;
    }
};
