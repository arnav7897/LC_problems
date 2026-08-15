class Solution {
public:

    int mah(vector<int>& h) {
        int n = h.size();

        stack<int> st;
        vector<int> nsl(n);
        vector<int> nsr(n);

        // Next Smaller to Left
        for (int i = 0; i < n; i++) {

            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            if (st.empty()) {
                nsl[i] = -1;
            } else {
                nsl[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller to Right
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            if (st.empty()) {
                nsr[i] = n;
            } else {
                nsr[i] = st.top();
            }

            st.push(i);
        }

        // Calculate maximum area
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = h[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> h(cols, 0);

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {
                    h[j]++;
                } else {
                    h[j] = 0;
                }
            }
            ans = max(ans, mah(h));
        }

        return ans;
    }
};