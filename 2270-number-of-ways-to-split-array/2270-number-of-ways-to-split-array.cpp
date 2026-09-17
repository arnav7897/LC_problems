class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> pre(n , 0);
        pre[0] = nums[0];
        for(long long i =1 ;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        int ans = 0;
        for(long long i =0 ;i<n-1;i++){
            if(pre[n-1] - pre[i] <= pre[i]){
                ans++;
            }
        }
        return ans;
    }
};