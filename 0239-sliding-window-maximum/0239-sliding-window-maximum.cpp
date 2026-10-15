class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        unordered_map<int, int> m;
        priority_queue<int> pq;

        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
            m[nums[i]]++;
        }

        for (int r = k - 1; r < n; r++) {
            while (!pq.empty() && m[pq.top()] == 0) {
                pq.pop();
            }

            ans.push_back(pq.top());

            if (r + 1 < n) {
                m[nums[r - k + 1]]--;
                pq.push(nums[r + 1]);
                m[nums[r + 1]]++;
            }
        }

        return ans;
    }
};