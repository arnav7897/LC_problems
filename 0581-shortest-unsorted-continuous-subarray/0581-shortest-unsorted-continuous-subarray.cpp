class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = -1 ,  r = -1;
        int maxi = nums[0];
        int mini = nums[n-1];
        for(int i = 1 ;i<n;i++){
            maxi = max(maxi , nums[i]);

            if(maxi > nums[i]){
                r = i;
            }
        }

        for(int i =n-2 ;i>=0 ;i--){
            mini = min(mini , nums[i]);

            if(mini < nums[i]){
                l = i;
            }
        }
        if(r == -1){
            return 0;
        }

        return r - l +1;
    }
};