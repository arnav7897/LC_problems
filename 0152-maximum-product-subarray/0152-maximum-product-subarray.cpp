class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long curr = nums[0];
        long long mini = nums[0];
        long long best = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            long long c1 = nums[i];
            long long c2 = curr * nums[i];
            long long c3 = mini * nums[i];

            curr = max(c1, max(c2, c3));
            mini = min(c1, min(c2, c3));

            best = max(best, curr);
        }

        return (int)best;
    }
};