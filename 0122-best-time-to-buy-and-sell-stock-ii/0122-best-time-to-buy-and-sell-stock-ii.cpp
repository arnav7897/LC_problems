class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_1  = 0;
        int dp_i_0 = 0;
        int curr_1 = 0;
        int curr_0 = 0 ;
        for(int i = n-1 ; i>=0 ; i--){
            curr_1 = max(dp_i_1 , dp_i_0 - prices[i]);
            curr_0 = max(dp_i_0 , dp_i_1 + prices[i]);
            dp_i_1 = curr_1;
            dp_i_0 = curr_0;
        }
        return curr_1;
    }
};