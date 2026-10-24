class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int maxi = 0;
        for(auto&it : nums){
            if(maxi == 0){
                res = it;
            }
            if(res == it){
                maxi++;
            }else{
                maxi--;
            }
        }
        return res;
    }
};