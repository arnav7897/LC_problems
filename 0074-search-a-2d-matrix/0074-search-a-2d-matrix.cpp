class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {

        int l = 0;
        int r = m.size() - 1;

        while(l < r) {
            int mid = l + (r-l+1)/2;

            if(m[mid][0] <= t) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        int lower = l;

        l = 0;
        r = m[0].size() - 1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(m[lower][mid] == t) {
                return true;
            }
            else if(m[lower][mid] > t) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return false;
    }
};