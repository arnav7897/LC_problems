class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int f = 0 ;
            for(int j = i ;j<n;j++){
                if(nums[j]== target){
                    f++;
                }
                if(2*f>j-i+1){
                    ans++;
                }
            }
        }
        return ans;
    }
};