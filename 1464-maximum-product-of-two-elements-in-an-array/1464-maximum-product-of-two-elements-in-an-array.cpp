class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MIN , m2 = INT_MIN;
        for(int i = 0;i<n;i++){
            if(nums[i]>m){
                m2 = m;
                m = nums[i];
            }else if(nums[i] > m2){
                m2 = nums[i];
            }
        }
        return (m-1)*(m2-1);
    }
};