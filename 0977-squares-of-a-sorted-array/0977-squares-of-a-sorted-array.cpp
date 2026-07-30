class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        int l = -1, r = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < 0 && nums[i] >= 0) {
                l = i - 1;
                r = i;
                break;
            }
        }
        if (nums[0] >= 0) {
            for (int x : nums)
                ans.push_back(x * x);
            return ans;
        }
        if (nums[n - 1] < 0) {
            for (int i = n - 1; i >= 0; i--)
                ans.push_back(nums[i] * nums[i]);
            return ans;
        }

        while (l >= 0 && r < n) {
            if (abs(nums[l]) <= abs(nums[r])) {
                ans.push_back(nums[l] * nums[l]);
                l--;
            } else {
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }

        while (l >= 0) {
            ans.push_back(nums[l] * nums[l]);
            l--;
        }

        while (r < n) {
            ans.push_back(nums[r] * nums[r]);
            r++;
        }

        return ans;
    }
};