class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int curr = arr[0];
        int best = arr[0];
        int oneDeleted = INT_MIN;

        for (int i = 1; i < n; i++) {
            int prev = curr;
            int prevOne = oneDeleted;

            curr = max(arr[i], prev + arr[i]);

            if (prevOne == INT_MIN)
                oneDeleted = prev;
            else
                oneDeleted = max(prev, prevOne + arr[i]);

            best = max(best, max(curr, oneDeleted));
        }

        return best;
    }
};
