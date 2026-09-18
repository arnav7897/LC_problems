class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = nums.size() - 1;
        if(n == 1){
            return nums[0];
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((m == 0 && nums[m] != nums[m + 1]) ||
                (m == n - 1 && nums[m] != nums[m - 1]) ||
                (nums[m] != nums[m - 1] && nums[m] != nums[m + 1])){
                    return nums[m];
                }
            if((m%2==0 && nums[m] == nums[m-1]) || (m%2!=0 && nums[m] == nums[m+1])){
                r = m -1;
            }else{
                l = m +1;
            }
        }
        return -1;
    }
};