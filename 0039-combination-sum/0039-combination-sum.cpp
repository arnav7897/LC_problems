class Solution {
public:
    void helper(vector<int>& c, int t, int i, vector<int>& cur, vector<vector<int>>& ans) {
        if (t == 0) {
            ans.push_back(cur);
            return;
        }
        if (i == c.size() || t < 0) return;

        cur.push_back(c[i]);
        helper(c, t - c[i], i, cur, ans);
        cur.pop_back();
        helper(c, t, i + 1, cur, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> cur;
        helper(c, t, 0, cur, ans);
        return ans;
    }
};
