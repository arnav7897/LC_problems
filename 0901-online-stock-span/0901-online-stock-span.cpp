class StockSpanner {
    stack<pair<int, int>> st;
    int idx;

public:
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        while (!st.empty() && price >= st.top().first) {
            st.pop();
        }

        int ans;

        if (st.empty()) {
            ans = idx + 1;
        } else {
            ans = idx - st.top().second;
        }

        st.push({price, idx});
        idx++;

        return ans;
    }
};