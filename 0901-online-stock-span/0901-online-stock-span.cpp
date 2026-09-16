class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx = 1;

    StockSpanner() {
    }

    int next(int price) {
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans;

        if (st.empty()) {
            ans = idx;
        } else {
            ans = idx - st.top().second;
        }

        st.push({price, idx});
        idx++;

        return ans;
    }
};