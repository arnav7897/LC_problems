class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int ans = -1;
        int n = nums.size();
        for(int i =0 ;i<n-1;i++){
            int l = i+1;
            int r = n-1;

            while(l<r){
                int total = nums[l]+nums[r]+nums[i];
                if(mini > abs(total - target)){
                    ans = total;
                    mini =  abs(total - target);
                }
                if(total == target){
                    return target;
                }else if(total < target){
                    l++;
                }else{
                    r--;
                } 
            }
        }
        return ans;
    }
};