class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int next_can_buy = 0;
        int next_must_sell = 0;

        for (int i = n - 1; i >= 0; i--) {
            int curr_must_sell = max(next_must_sell, p[i]);
            int curr_can_buy = max(next_can_buy, next_must_sell - p[i]);
            next_must_sell = curr_must_sell;
            next_can_buy = curr_can_buy;
        }

        return next_can_buy;
    }
};
