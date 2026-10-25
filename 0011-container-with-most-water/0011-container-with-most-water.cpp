class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = 0;   
        while( l < r ){
            int temp = min(nums[r] , nums[l])*(r-l);
            ans = max(ans , temp);
            if(nums[r] == nums[l]){
                l++;
                r--;
            }else if(nums[r] < nums[l]){
                r--;
            }else{
                l++;
            }
        }
        return ans;
    }
};