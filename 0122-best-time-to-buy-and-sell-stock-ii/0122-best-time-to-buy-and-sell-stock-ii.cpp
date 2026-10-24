class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int canbuy  = 0;
        int can_sell = 0;
        int curr_buying = 0;
        int curr_selling = 0 ;
        for(int i = n-1 ; i>=0 ; i--){
            curr_buying = max(canbuy , can_sell - prices[i]);
            curr_selling = max(can_sell , canbuy + prices[i]);
            canbuy = curr_buying;
            can_sell = curr_selling;
        }
        return curr_buying;
    }
};