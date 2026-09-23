class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        for (auto& it : nums) {
            sum += it;
        }
        if (sum - x < 0) {
            return -1;
        } else if (sum - x == 0) {
            return n;
        }
        int target = sum - x;
        int ans = -1;
        sum = 0;
        while (r < n) {
            sum += nums[r];
            if (sum == target) {
                ans = max(ans, r - l + 1);
            } else if (sum > target) {
                while (sum > target) {
                    sum -= nums[l];
                    l++;
                }
                if (sum == target) {
                    ans = max(ans, r - l + 1);
                }
            }
            r++;
        }
        if (ans == -1) {
            return -1;
        } else {
            return n - (ans);
        }
    }
};